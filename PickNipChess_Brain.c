#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

enum{false,true};
typedef int bool;

//棋盘大小(包裹两层)
#define ROW 16
#define COL 16
//棋子颜色
#define GAP	  0
#define BLACK 1
#define WHITE 2

//8个方向
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define UP_LEFT 4
#define UP_RIGHT 5
#define DOWN_LEFT 6
#define DOWN_RIGHT 7

#define RET_EAT      1
#define RET_WALKNUM  2
#define RET_COHESION 1
#define RET_POSVALUE 1


#define YY 0
#define AA 10
#define BB 5
#define CC 1
#define DD -1
int POSVALUE[ROW][COL] =
{
	YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,
	YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,
	YY,YY,AA,AA,AA,BB,BB,CC,CC,BB,BB,AA,AA,AA,YY,YY,
	YY,YY,AA,AA,BB,BB,CC,CC,CC,CC,BB,BB,AA,AA,YY,YY,
	YY,YY,AA,BB,BB,CC,CC,DD,DD,CC,CC,BB,BB,AA,YY,YY,
	YY,YY,BB,BB,CC,CC,DD,DD,DD,DD,CC,CC,BB,BB,YY,YY,
	YY,YY,BB,CC,CC,DD,DD,DD,DD,DD,DD,CC,CC,BB,YY,YY,
	YY,YY,CC,CC,DD,DD,DD,DD,DD,DD,DD,DD,CC,CC,YY,YY,
	YY,YY,CC,CC,DD,DD,DD,DD,DD,DD,DD,DD,CC,CC,YY,YY,
	YY,YY,BB,CC,CC,DD,DD,DD,DD,DD,DD,CC,CC,BB,YY,YY,
	YY,YY,BB,BB,CC,CC,DD,DD,DD,DD,CC,CC,BB,BB,YY,YY,
	YY,YY,AA,BB,BB,CC,CC,DD,DD,CC,CC,BB,BB,AA,YY,YY,
	YY,YY,AA,AA,BB,BB,CC,CC,CC,CC,BB,BB,AA,AA,YY,YY,
	YY,YY,AA,AA,AA,BB,BB,CC,CC,BB,BB,AA,AA,AA,YY,YY,
	YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,
	YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,
};
///////////////////////////////////////////
/*链表操作*/
typedef struct Chess Chess;
typedef struct LinkList LinkList;

struct Chess
{
	int x;					//当前步的信息
	int y;
	int option;
	int pick_num, nip_num;	//走当前步可以挑吃和夹持的数量

	int Ywalk_next;			//对方下局的行动力

	int Mcohesion_next;			//我方的凝聚力
	int Ycohesion_next;			//对方的凝聚力

	int Mmapvalue_next;				//棋盘位置值
	int Ymapvalue_next;
};
struct NODE
{
	struct Chess data;
	struct NODE *next;
};
struct LinkList
{
	struct NODE *head;
	struct NODE *rear;
};

void CreateLink(LinkList *list)
{
	list->head = list->rear = malloc(sizeof*list->head);
	struct NODE *move = list->head;
	move->next = NULL;
}
void DestroyLink(LinkList *list)
{
	struct NODE *save;
	while (list->head)
	{
		save = list->head;
		list->head = list->head->next;
		free(save);
		save = NULL;
	}
}
void Push_back(LinkList *list, Chess *buf)
{
	struct NODE *fresh = malloc(sizeof*fresh);
	fresh->data = *buf;
	fresh->next = NULL;

	list->rear->next = fresh;
	list->rear = list->rear->next;		//更新尾指针
}
void FindMaxValue(LinkList *list, Chess *save)
{
	struct NODE *move = list->head->next;
	int maxvalue =
		(move->data.nip_num + move->data.pick_num)*RET_EAT
		- move->data.Ywalk_next*RET_WALKNUM
		+ move->data.Mcohesion_next*RET_COHESION
		- move->data.Ycohesion_next*RET_COHESION
		+ move->data.Mmapvalue_next*RET_POSVALUE
		- move->data.Ymapvalue_next*RET_POSVALUE;

	Chess buf = move->data;

	
	for (move=move->next; move != NULL; move = move->next)
	{
		if (move->data.Ywalk_next < maxvalue)
		{
			maxvalue = 
				(move->data.nip_num + move->data.pick_num)*RET_EAT
				- move->data.Ywalk_next*RET_WALKNUM
				+ move->data.Mcohesion_next*RET_COHESION
				- move->data.Ycohesion_next*RET_COHESION;

			buf = move->data;
		}
	}

	*save = buf;
}
////////////////////////////////////////////


/*显示整个棋盘*/
void showMap(int Map[][COL])
{
	printf("****************************************\n");
	printf("\x20\x20\x20");
	for (int i = 2; i < 14; ++i)
	{
		printf("%3d", i-2);
	}
	printf("\n");
	for (int i = 2; i < 14; ++i)
	{
		printf("%3d", i-2);
		for (int j = 2; j < 14; ++j)
		{
			printf("%3d", Map[i][j]);
		}
		printf("\n");
	}

	printf("****************************************\n");
}
/*移动某方棋子*/		//不做任何检测
void setMap(int color, int x, int y, int option, int Map[][COL])
{
	switch (option)
	{
	case UP:
	{
		Map[x - 1][y] = color;
		break;
	}
	case DOWN:
	{
		Map[x + 1][y] = color;
		break;
	}
	case LEFT:
	{
		Map[x][y - 1] = color;
		break;
	}
	case RIGHT:
	{
		Map[x][y + 1] = color;
		break;
	}
	case UP_LEFT:
	{
		Map[x - 1][y - 1] = color;
		break;
	}
	case UP_RIGHT:
	{
		Map[x - 1][y + 1] = color;
		break;
	}
	case DOWN_LEFT:
	{
		Map[x + 1][y - 1] = color;
		break;
	}
	case DOWN_RIGHT:
	{
		Map[x + 1][y + 1] = color;
		break;
	}
	default:break;
	}
	Map[x][y] = GAP;

}
/*某方向是否可走*/
bool canWalk(int x, int y, int option, int Map[][COL])
{
	switch (option)
	{
	case UP:
	{
		if (x - 1 == 1) { return false; }		//出界判断

		if (Map[x - 1][y] == GAP) { return true; }
		else { return false; }

		break;
	}
	case DOWN:
	{
		if (x + 1 == 14) { return false; }

		if (Map[x + 1][y] == GAP) { return true; }
		else { return false; }

		break;
	}
	case LEFT:
	{
		if (y - 1 == 1) { return false; }

		if (Map[x][y - 1] == GAP) { return true; }
		else { return false; }

		break;
	}
	case RIGHT:
	{
		if (y + 1 == 14) { return false; }

		if (Map[x][y + 1] == GAP) { return true; }
		else { return false; }

		break;
	}
	case UP_LEFT:
	{
		if (x - 1 == 1 || y - 1 == 1) { return false; }

		if (Map[x - 1][y - 1] == GAP) { return true; }
		else { return false; }

		break;
	}
	case UP_RIGHT:
	{
		if (x - 1 == 1 || y + 1 == 14) { return false; }

		if (Map[x - 1][y + 1] == GAP) { return true; }
		else { return false; }

		break;
	}
	case DOWN_LEFT:
	{
		if (x + 1 == 14 || y - 1 == 1) { return false; }

		if (Map[x + 1][y - 1] == GAP) { return true; }
		else { return false; }

		break;
	}
	case DOWN_RIGHT:
	{
		if (x + 1 == 14 || y + 1 == 14) { return false; }

		if (Map[x + 1][y + 1] == GAP) { return true; }
		else { return false; }

		break;
	}
	default:return false; break;
	}
}
/*挑吃*/
int PickChess(int Ycolor, int x, int y, int option, int Map[][COL])
{
	int cnt = 0;

	switch (option)
	{
	case UP:
	{
		if (Map[x - 1][y - 1] == Ycolor && Map[x - 1][y + 1] == Ycolor) {
			Map[x - 1][y - 1] = Map[x - 1][y + 1] == 3 - Ycolor;
		}
		if (Map[x - 2][y - 1] == Ycolor && Map[x][y + 1] == Ycolor) {
			Map[x - 2][y - 1] = Map[x][y + 1] = 3 - Ycolor;
		}
		if (Map[x][y - 1] == Ycolor && Map[x - 2][y + 1] == Ycolor) {
			Map[x][y - 1] = Map[x - 2][y + 1] = 3 - Ycolor;
		}

		break;
	}
	case DOWN:
	{
		if (Map[x + 1][y - 1] == Ycolor && Map[x + 1][y + 1] == Ycolor) {
			Map[x + 1][y - 1] = Map[x + 1][y + 1] = 3 - Ycolor;
		}
		if (Map[x][y - 1] == Ycolor && Map[x + 2][y + 1] == Ycolor) {
			Map[x][y - 1] = Map[x + 2][y + 1] = 3 - Ycolor;
		}
		if (Map[x + 2][y - 1] == Ycolor && Map[x][y + 1] == Ycolor) {
			Map[x + 2][y - 1] = Map[x][y + 1] = 3 - Ycolor;
		}

		break;
	}
	case LEFT:
	{
		if (Map[x - 1][y - 1] == Ycolor && Map[x + 1][y - 1] == Ycolor) {
			Map[x - 1][y - 1] = Map[x + 1][y - 1] = 3 - Ycolor;
		}
		if (Map[x - 1][y - 2] == Ycolor && Map[x + 1][y] == Ycolor) {
			Map[x - 1][y - 2] = Map[x + 1][y] = 3 - Ycolor;
		}
		if (Map[x + 1][y - 2] == Ycolor && Map[x - 1][y] == Ycolor) {
			Map[x + 1][y - 2] = Map[x - 1][y] = 3 - Ycolor;
		}

		break;
	}
	case RIGHT:
	{
		if (Map[x - 1][y + 1] == Ycolor && Map[x + 1][y + 1] == Ycolor) {
			Map[x - 1][y + 1] = Map[x + 1][y + 1] = 3 - Ycolor;
		}
		if (Map[x - 1][y] == Ycolor && Map[x + 1][y + 2] == Ycolor) {
			Map[x - 1][y] = Map[x + 1][y + 2] = 3 - Ycolor;
		}
		if (Map[x + 1][y] == Ycolor && Map[x - 1][y + 2] == Ycolor) {
			Map[x + 1][y] = Map[x - 1][y + 2] = 3 - Ycolor;
		}

		break;
	}
	case UP_LEFT:
	{
		if (Map[x - 2][y - 1] == Ycolor && Map[x][y - 1] == Ycolor) {
			Map[x - 2][y - 1] = Map[x][y - 1] = 3 - Ycolor;
		}
		if (Map[x - 1][y - 2] == Ycolor && Map[x - 1][y] == Ycolor) {
			Map[x - 1][y - 2] = Map[x - 1][y] = 3 - Ycolor;
		}
		if (Map[x][y - 2] == Ycolor && Map[x - 2][y] == Ycolor) {
			Map[x][y - 2] = Map[x - 2][y] = 3 - Ycolor;
		}

		break;
	}
	case UP_RIGHT:
	{
		if (Map[x - 2][y + 1] == Ycolor && Map[x][y + 1] == Ycolor) {
			Map[x - 2][y + 1] = Map[x][y + 1] = 3 - Ycolor;
		}
		if (Map[x - 2][y] == Ycolor && Map[x][y + 2] == Ycolor) {
			Map[x - 2][y] = Map[x][y + 2] = 3 - Ycolor;
		}
		if (Map[x - 1][y] == Ycolor && Map[x - 1][y + 2] == Ycolor) {
			Map[x - 1][y] = Map[x - 1][y + 2] = 3 - Ycolor;
		}

		break;
	}
	case DOWN_LEFT:
	{
		if (Map[x][y - 1] == Ycolor && Map[x + 2][y - 1] == Ycolor) {
			Map[x][y - 1] = Map[x + 2][y - 1] = 3 - Ycolor;
		}
		if (Map[x + 1][y - 2] == Ycolor && Map[x + 1][y] == Ycolor) {
			Map[x + 1][y - 2] = Map[x + 1][y] = 3 - Ycolor;
		}
		if (Map[x][y - 2] == Ycolor && Map[x + 2][y] == Ycolor) {
			Map[x][y - 2] = Map[x + 2][y] = 3 - Ycolor;
		}

		break;
	}
	case DOWN_RIGHT:
	{
		if (Map[x][y + 1] == Ycolor && Map[x + 2][y + 1] == Ycolor) {
			Map[x][y + 1] = Map[x + 2][y + 1] = 3 - Ycolor;
		}
		if (Map[x + 1][y] == Ycolor && Map[x + 1][y + 2] == Ycolor) {
			Map[x + 1][y] = Map[x + 1][y + 2] = 3 - Ycolor;
		}
		if (Map[x + 2][y] == Ycolor && Map[x][y + 2] == Ycolor) {
			Map[x + 2][y] = Map[x][y + 2] = 3 - Ycolor;
		}

		break;
	}
	default:break;
	}

	return cnt;
}
/*夹吃*/
int NipChess(int Ycolor, int x, int y, int option, int Map[][COL])
{
	int cnt = 0;
	switch (option)
	{
	case UP:
	{
		if (Map[x - 2][y - 1] == Ycolor && Map[x - 3][y - 2] == 3 - Ycolor) {
			Map[x - 2][y - 1] = 3 - Ycolor;
		}
		if (Map[x - 2][y] == Ycolor && Map[x - 3][y] == 3 - Ycolor) {
			Map[x - 2][y] = 3 - Ycolor;
		}
		if (Map[x - 2][y + 1] == Ycolor && Map[x - 3][y + 2] == 3 - Ycolor) {
			Map[x - 2][y + 1] = 3 - Ycolor;
		}
		if (Map[x - 1][y - 1] == Ycolor && Map[x - 1][y - 2] == 3 - Ycolor) {
			Map[x - 1][y - 1] = 3 - Ycolor;
		}
		if (Map[x][y - 1] == Ycolor && Map[x + 1][y - 2] == 3 - Ycolor) {
			Map[x][y - 1] = 3 - Ycolor;
		}
		if (Map[x][y + 1] == Ycolor && Map[x + 1][y + 2] == 3 - Ycolor) {
			Map[x][y + 1] = 3 - Ycolor;
		}

		break;
	}
	case DOWN:
	{
		if (Map[x][y - 1] == Ycolor && Map[x - 1][y - 2] == 3 - Ycolor) {
			Map[x][y - 1] = 3 - Ycolor;
		}
		if (Map[x][y + 1] == Ycolor && Map[x - 1][y + 2] == 3 - Ycolor) {
			Map[x][y + 1] = 3 - Ycolor;
		}
		if (Map[x + 1][y - 1] == Ycolor && Map[x - 1][y - 2] == 3 - Ycolor) {
			Map[x + 1][y - 1] = 3 - Ycolor;
		}
		if (Map[x + 1][y + 1] == Ycolor && Map[x + 1][y + 2] == 3 - Ycolor) {
			Map[x + 1][y + 1] = 3 - Ycolor;
		}
		if (Map[x + 2][y - 1] == Ycolor && Map[x + 3][y - 2] == 3 - Ycolor) {
			Map[x + 2][y - 1] = 3 - Ycolor;
		}
		if (Map[x + 2][y] == Ycolor && Map[x + 3][y] == 3 - Ycolor) {
			Map[x + 2][y] = 3 - Ycolor;
		}
		if (Map[x + 2][y + 1] == Ycolor && Map[x + 3][y + 2] == 3 - Ycolor) {
			Map[x + 2][y + 1] = 3 - Ycolor;
		}

		break;
	}
	case LEFT:
	{
		if (Map[x - 1][y - 2] == Ycolor && Map[x - 2][y - 3] == 3 - Ycolor) {
			Map[x - 1][y - 2] = 3 - Ycolor;
		}
		if (Map[x - 1][y - 1] == Ycolor && Map[x - 2][y - 1] == 3 - Ycolor) {
			Map[x - 1][y - 1] = 3 - Ycolor;
		}
		if (Map[x - 1][y] == Ycolor && Map[x - 2][y + 1] == 3 - Ycolor) {
			Map[x - 1][y] = 3 - Ycolor;
		}
		if (Map[x][y - 2] == Ycolor && Map[x][y - 3] == 3 - Ycolor) {
			Map[x][y - 2] = 3 - Ycolor;
		}
		if (Map[x + 1][y - 2] == Ycolor && Map[x + 2][y - 3] == 3 - Ycolor) {
			Map[x + 1][y - 2] = 3 - Ycolor;
		}
		if (Map[x + 1][y - 1] == Ycolor && Map[x + 2][y - 1] == 3 - Ycolor) {
			Map[x + 1][y - 1] = 3 - Ycolor;
		}
		if (Map[x + 1][y] == Ycolor && Map[x + 2][y + 1] == 3 - Ycolor) {
			Map[x + 1][y] = 3 - Ycolor;
		}

		break;
	}
	case RIGHT:
	{
		if (Map[x - 1][y] == Ycolor && Map[x - 2][y - 1] == 3 - Ycolor) {
			Map[x - 1][y] = 3 - Ycolor;
		}
		if (Map[x - 1][y + 1] == Ycolor && Map[x - 2][y + 1] == 3 - Ycolor) {
			Map[x - 1][y + 1] = 3 - Ycolor;
		}
		if (Map[x - 1][y + 2] == Ycolor && Map[x - 2][y + 3] == 3 - Ycolor) {
			Map[x - 1][y + 2] = 3 - Ycolor;
		}
		if (Map[x][y + 2] == Ycolor && Map[x][y + 3] == 3 - Ycolor) {
			Map[x][y + 2] = 3 - Ycolor;
		}
		if (Map[x + 1][y] == Ycolor && Map[x - 2][y - 1] == 3 - Ycolor) {
			Map[x + 1][y] = 3 - Ycolor;
		}
		if (Map[x + 1][y + 1] == Ycolor && Map[x + 2][y + 1] == 3 - Ycolor) {
			Map[x + 1][y + 1] = 3 - Ycolor;
		}
		if (Map[x + 1][y + 2] == Ycolor && Map[x + 2][y + 3] == 3 - Ycolor) {
			Map[x + 1][y + 2] = 3 - Ycolor;
		}

		break;
	}
	case UP_LEFT:
	{
		if (Map[x - 2][y - 2] == Ycolor && Map[x - 3][y - 3] == 3 - Ycolor) {
			Map[x - 2][y - 2] = 3 - Ycolor;
		}
		if (Map[x - 2][y - 1] == Ycolor && Map[x - 3][y - 1] == 3 - Ycolor) {
			Map[x - 2][y - 1] = 3 - Ycolor;
		}
		if (Map[x - 2][y] == Ycolor && Map[x - 3][y + 1] == 3 - Ycolor) {
			Map[x - 2][y] = 3 - Ycolor;
		}
		if (Map[x - 1][y - 2] == Ycolor && Map[x - 1][y - 3] == 3 - Ycolor) {
			Map[x - 1][y - 2] = 3 - Ycolor;
		}
		if (Map[x - 1][y] == Ycolor && Map[x - 1][y + 1] == 3 - Ycolor) {
			Map[x - 1][y] = 3 - Ycolor;
		}
		if (Map[x][y - 2] == Ycolor && Map[x + 1][y - 1] == 3 - Ycolor) {
			Map[x][y - 2] = 3 - Ycolor;
		}
		if (Map[x][y - 1] == Ycolor && Map[x + 1][y - 1] == 3 - Ycolor) {
			Map[x][y - 1] = 3 - Ycolor;
		}
		break;
	}
	case UP_RIGHT:
	{
		if (Map[x - 2][y] == Ycolor && Map[x - 3][y - 1] == 3 - Ycolor) {
			Map[x - 2][y] = 3 - Ycolor;
		}
		if (Map[x - 2][y + 1] == Ycolor && Map[x - 3][y + 1] == 3 - Ycolor) {
			Map[x - 2][y + 1] = 3 - Ycolor;
		}
		if (Map[x - 2][y + 2] == Ycolor && Map[x - 3][y + 3] == 3 - Ycolor) {
			Map[x - 2][y + 2] = 3 - Ycolor;
		}
		if (Map[x - 1][y] == Ycolor && Map[x - 1][y - 1] == 3 - Ycolor) {
			Map[x - 1][y] = 3 - Ycolor;
		}
		if (Map[x - 1][y + 2] == Ycolor && Map[x - 1][y + 3] == 3 - Ycolor) {
			Map[x - 1][y + 2] = 3 - Ycolor;
		}
		if (Map[x][y + 1] == Ycolor && Map[x + 1][y + 1] == 3 - Ycolor) {
			Map[x][y + 1] = 3 - Ycolor;
		}
		if (Map[x][y + 2] == Ycolor && Map[x + 1][y + 3] == 3 - Ycolor) {
			Map[x][y + 2] = 3 - Ycolor;
		}

		break;
	}
	case DOWN_LEFT:
	{
		if (Map[x][y - 2] == Ycolor && Map[x - 1][y - 3] == 3 - Ycolor) {
			Map[x][y - 2] = 3 - Ycolor;
		}
		if (Map[x][y - 1] == Ycolor && Map[x - 1][y - 1] == 3 - Ycolor) {
			Map[x][y - 1] = 3 - Ycolor;
		}
		if (Map[x + 1][y - 2] == Ycolor && Map[x + 1][y - 3] == 3 - Ycolor) {
			Map[x + 1][y - 2] = 3 - Ycolor;
		}
		if (Map[x + 1][y] == Ycolor && Map[x + 1][y + 1] == 3 - Ycolor) {
			Map[x + 1][y] = 3 - Ycolor;
		}
		if (Map[x + 2][y - 2] == Ycolor && Map[x + 3][y - 3] == 3 - Ycolor) {
			Map[x + 2][y - 2] = 3 - Ycolor;
		}
		if (Map[x + 2][y - 1] == Ycolor && Map[x + 3][y - 1] == 3 - Ycolor) {
			Map[x + 2][y - 1] = 3 - Ycolor;
		}
		if (Map[x + 2][y] == Ycolor && Map[x + 3][y + 1] == 3 - Ycolor) {
			Map[x + 2][y] = 3 - Ycolor;
		}

		break;
	}
	case DOWN_RIGHT:
	{
		if (Map[x][y + 1] == Ycolor && Map[x - 1][y + 1] == 3 - Ycolor) {
			Map[x][y + 1] = 3 - Ycolor;
		}
		if (Map[x][y + 2] == Ycolor && Map[x - 1][y + 3] == 3 - Ycolor) {
			Map[x][y + 2] = 3 - Ycolor;
		}
		if (Map[x + 1][y] == Ycolor && Map[x + 1][y - 1] == 3 - Ycolor) {
			Map[x + 1][y] = 3 - Ycolor;
		}
		if (Map[x + 1][y + 2] == Ycolor && Map[x + 1][y + 3] == 3 - Ycolor) {
			Map[x + 1][y + 2] = 3 - Ycolor;
		}
		if (Map[x + 2][y] == Ycolor && Map[x + 3][y - 1] == 3 - Ycolor) {
			Map[x + 2][y] = 3 - Ycolor;
		}
		if (Map[x + 2][y + 1] == Ycolor && Map[x + 3][y + 1] == 3 - Ycolor) {
			Map[x + 2][y + 1] = 3 - Ycolor;
		}
		if (Map[x + 2][y + 2] == Ycolor && Map[x + 3][y + 3] == 3 - Ycolor) {
			Map[x + 2][y + 2] = 3 - Ycolor;
		}

		break;
	}
	default:break;
	}
	return cnt;
}

/*我走子之后调整棋盘*/
void ChangeMap(int Mcolor, int x, int y, int option, int Map[][COL])
{
	PickChess(3 - Mcolor, x, y, option, Map);
	NipChess(3 - Mcolor, x, y, option, Map);
}

/*color方的凝聚力*/
int Cohesion(int color, int Map[][COL])
{
	int cohesion = 0;
	for (int i = 2; i < 14; ++i)
	{
		for (int j = 2; j < 14; ++j)
		{
			if (Map[i][j] == color)
			{
				for (int a = -1; a < 2; ++a)
				{
					for (int b = -1; b < 2; ++b)
					{
						if (Map[i + 1][j + b] == color)
						{
							cohesion++;
						}
					}
				}
			}
		}
	}

	return cohesion;
}
/*color方的棋盘值*/
int MapValue(int color, int Map[][COL])
{
	int mapvalue = 0;
	for (int i = 2; i < 14; ++i)
	{
		for (int j = 2; j < 14; ++j)
		{
			if (Map[i][j] == color)
			{
				mapvalue++;
			}
		}
	}

	return mapvalue;
}


/*这样的走子 挑吃个数*/
int PickNum(int Ycolor, int x, int y, int option, int Map[][COL])
{
	int cnt = 0;

	switch (option)
	{
	case UP:
	{
		if (Map[x - 1][y - 1] == Ycolor && Map[x - 1][y + 1] == Ycolor) { cnt += 2; }
		if (Map[x - 2][y - 1] == Ycolor && Map[x][y + 1] == Ycolor) { cnt += 2; }
		if (Map[x][y - 1] == Ycolor && Map[x - 2][y + 1] == Ycolor) { cnt += 2; }

		break;
	}
	case DOWN:
	{
		if (Map[x + 1][y - 1] == Ycolor && Map[x + 1][y + 1] == Ycolor) { cnt += 2; }
		if (Map[x][y - 1] == Ycolor && Map[x + 2][y + 1] == Ycolor) { cnt += 2; }
		if (Map[x + 2][y - 1] == Ycolor && Map[x][y + 1] == Ycolor) { cnt += 2; }

		break;
	}
	case LEFT:
	{
		if (Map[x - 1][y - 1] == Ycolor && Map[x + 1][y - 1] == Ycolor) { cnt += 2; }
		if (Map[x - 1][y - 2] == Ycolor && Map[x + 1][y] == Ycolor) { cnt += 2; }
		if (Map[x + 1][y - 2] == Ycolor && Map[x - 1][y] == Ycolor) { cnt += 2; }

		break;
	}
	case RIGHT:
	{
		if (Map[x - 1][y + 1] == Ycolor && Map[x + 1][y + 1] == Ycolor) { cnt += 2; }
		if (Map[x - 1][y] == Ycolor && Map[x + 1][y + 2] == Ycolor) { cnt += 2; }
		if (Map[x + 1][y] == Ycolor && Map[x - 1][y + 2] == Ycolor) { cnt += 2; }

		break;
	}
	case UP_LEFT:
	{
		if (Map[x - 2][y - 1] == Ycolor && Map[x][y - 1] == Ycolor) { cnt += 2; }
		if (Map[x - 1][y - 2] == Ycolor && Map[x - 1][y] == Ycolor) { cnt += 2; }
		if (Map[x][y - 2] == Ycolor && Map[x - 2][y] == Ycolor) { cnt += 2; }

		break;
	}
	case UP_RIGHT:
	{
		if (Map[x - 2][y + 1] == Ycolor && Map[x][y + 1] == Ycolor) { cnt += 2; }
		if (Map[x - 2][y] == Ycolor && Map[x][y + 2] == Ycolor) { cnt += 2; }
		if (Map[x - 1][y] == Ycolor && Map[x - 1][y + 2] == Ycolor) { cnt += 2; }

		break;
	}
	case DOWN_LEFT:
	{
		if (Map[x][y - 1] == Ycolor && Map[x + 2][y - 1] == Ycolor) { cnt += 2; }
		if (Map[x + 1][y - 2] == Ycolor && Map[x + 1][y] == Ycolor) { cnt += 2; }
		if (Map[x][y - 2] == Ycolor && Map[x + 2][y] == Ycolor) { cnt += 2; }

		break;
	}
	case DOWN_RIGHT:
	{
		if (Map[x][y + 1] == Ycolor && Map[x + 2][y + 1] == Ycolor) { cnt += 2; }
		if (Map[x + 1][y] == Ycolor && Map[x + 1][y + 2] == Ycolor) { cnt += 2; }
		if (Map[x + 2][y] == Ycolor && Map[x][y + 2] == Ycolor) { cnt += 2; }

		break;
	}
	default:break;
	}

	return cnt;
}
/*这样的走子 夹吃个数*/
int NipNum(int Ycolor, int x, int y, int option, int Map[][COL])
{
	int cnt = 0;
	switch (option)
	{
	case UP:
	{
		if (Map[x - 2][y - 1] == Ycolor && Map[x - 3][y - 2] == 3 - Ycolor) { cnt++; }
		if (Map[x - 2][y] == Ycolor && Map[x - 3][y] == 3 - Ycolor) { cnt++; }
		if (Map[x - 2][y + 1] == Ycolor && Map[x - 3][y + 2] == 3 - Ycolor) { cnt++; }
		if (Map[x - 1][y - 1] == Ycolor && Map[x - 1][y - 2] == 3 - Ycolor) { cnt++; }
		if (Map[x][y - 1] == Ycolor && Map[x + 1][y - 2] == 3 - Ycolor) { cnt++; }
		if (Map[x][y + 1] == Ycolor && Map[x + 1][y + 2] == 3 - Ycolor) { cnt++; }

		break;
	}
	case DOWN:
	{
		if (Map[x][y - 1] == Ycolor && Map[x - 1][y - 2] == 3 - Ycolor) { cnt++; }
		if (Map[x][y + 1] == Ycolor && Map[x - 1][y + 2] == 3 - Ycolor) { cnt++; }
		if (Map[x + 1][y - 1] == Ycolor && Map[x - 1][y - 2] == 3 - Ycolor) { cnt++; }
		if (Map[x + 1][y + 1] == Ycolor && Map[x + 1][y + 2] == 3 - Ycolor) { cnt++; }
		if (Map[x + 2][y - 1] == Ycolor && Map[x + 3][y - 2] == 3 - Ycolor) { cnt++; }
		if (Map[x + 2][y] == Ycolor && Map[x + 3][y] == 3 - Ycolor) { cnt++; }
		if (Map[x + 2][y + 1] == Ycolor && Map[x + 3][y + 2] == 3 - Ycolor) { cnt++; }

		break;
	}
	case LEFT:
	{
		if (Map[x - 1][y - 2] == Ycolor && Map[x - 2][y - 3] == 3 - Ycolor) { cnt++; }
		if (Map[x - 1][y - 1] == Ycolor && Map[x - 2][y - 1] == 3 - Ycolor) { cnt++; }
		if (Map[x - 1][y] == Ycolor && Map[x - 2][y + 1] == 3 - Ycolor) { cnt++; }
		if (Map[x][y - 2] == Ycolor && Map[x][y - 3] == 3 - Ycolor) { cnt++; }
		if (Map[x + 1][y - 2] == Ycolor && Map[x + 2][y - 3] == 3 - Ycolor) { cnt++; }
		if (Map[x + 1][y - 1] == Ycolor && Map[x + 2][y - 1] == 3 - Ycolor) { cnt++; }
		if (Map[x + 1][y] == Ycolor && Map[x + 2][y + 1] == 3 - Ycolor) { cnt++; }

		break;
	}
	case RIGHT:
	{
		if (Map[x - 1][y] == Ycolor && Map[x - 2][y - 1] == 3 - Ycolor) { cnt++; }
		if (Map[x - 1][y + 1] == Ycolor && Map[x - 2][y + 1] == 3 - Ycolor) { cnt++; }
		if (Map[x - 1][y + 2] == Ycolor && Map[x - 2][y + 3] == 3 - Ycolor) { cnt++; }
		if (Map[x][y + 2] == Ycolor && Map[x][y + 3] == 3 - Ycolor) { cnt++; }
		if (Map[x + 1][y] == Ycolor && Map[x - 2][y - 1] == 3 - Ycolor) { cnt++; }
		if (Map[x + 1][y + 1] == Ycolor && Map[x + 2][y + 1] == 3 - Ycolor) { cnt++; }
		if (Map[x + 1][y + 2] == Ycolor && Map[x + 2][y + 3] == 3 - Ycolor) { cnt++; }

		break;
	}
	case UP_LEFT:
	{
		if (Map[x - 2][y - 2] == Ycolor && Map[x - 3][y - 3] == 3 - Ycolor) { cnt++; }
		if (Map[x - 2][y - 1] == Ycolor && Map[x - 3][y - 1] == 3 - Ycolor) { cnt++; }
		if (Map[x - 2][y] == Ycolor && Map[x - 3][y + 1] == 3 - Ycolor) { cnt++; }
		if (Map[x - 1][y - 2] == Ycolor && Map[x - 1][y - 3] == 3 - Ycolor) { cnt++; }
		if (Map[x - 1][y] == Ycolor && Map[x - 1][y + 1] == 3 - Ycolor) { cnt++; }
		if (Map[x][y - 2] == Ycolor && Map[x + 1][y - 1] == 3 - Ycolor) { cnt++; }
		if (Map[x][y - 1] == Ycolor && Map[x + 1][y - 1] == 3 - Ycolor) { cnt++; }
		break;
	}
	case UP_RIGHT:
	{
		if (Map[x - 2][y] == Ycolor && Map[x - 3][y - 1] == 3 - Ycolor) { cnt++; }
		if (Map[x - 2][y + 1] == Ycolor && Map[x - 3][y + 1] == 3 - Ycolor) { cnt++; }
		if (Map[x - 2][y + 2] == Ycolor && Map[x - 3][y + 3] == 3 - Ycolor) { cnt++; }
		if (Map[x - 1][y] == Ycolor && Map[x - 1][y - 1] == 3 - Ycolor) { cnt++; }
		if (Map[x - 1][y + 2] == Ycolor && Map[x - 1][y + 3] == 3 - Ycolor) { cnt++; }
		if (Map[x][y + 1] == Ycolor && Map[x + 1][y + 1] == 3 - Ycolor) { cnt++; }
		if (Map[x][y + 2] == Ycolor && Map[x + 1][y + 3] == 3 - Ycolor) { cnt++; }

		break;
	}
	case DOWN_LEFT:
	{
		if (Map[x][y - 2] == Ycolor && Map[x - 1][y - 3] == 3 - Ycolor) { cnt++; }
		if (Map[x][y - 1] == Ycolor && Map[x - 1][y - 1] == 3 - Ycolor) { cnt++; }
		if (Map[x + 1][y - 2] == Ycolor && Map[x + 1][y - 3] == 3 - Ycolor) { cnt++; }
		if (Map[x + 1][y] == Ycolor && Map[x + 1][y + 1] == 3 - Ycolor) { cnt++; }
		if (Map[x + 2][y - 2] == Ycolor && Map[x + 3][y - 3] == 3 - Ycolor) { cnt++; }
		if (Map[x + 2][y - 1] == Ycolor && Map[x + 3][y - 1] == 3 - Ycolor) { cnt++; }
		if (Map[x + 2][y] == Ycolor && Map[x + 3][y + 1] == 3 - Ycolor) { cnt++; }

		break;
	}
	case DOWN_RIGHT:
	{
		if (Map[x][y + 1] == Ycolor && Map[x - 1][y + 1] == 3 - Ycolor) { cnt++; }
		if (Map[x][y + 2] == Ycolor && Map[x - 1][y + 3] == 3 - Ycolor) { cnt++; }
		if (Map[x + 1][y] == Ycolor && Map[x + 1][y - 1] == 3 - Ycolor) { cnt++; }
		if (Map[x + 1][y + 2] == Ycolor && Map[x + 1][y + 3] == 3 - Ycolor) { cnt++; }
		if (Map[x + 2][y] == Ycolor && Map[x + 3][y - 1] == 3 - Ycolor) { cnt++; }
		if (Map[x + 2][y + 1] == Ycolor && Map[x + 3][y + 1] == 3 - Ycolor) { cnt++; }
		if (Map[x + 2][y + 2] == Ycolor && Map[x + 3][y + 3] == 3 - Ycolor) { cnt++; }

		break;
	}
	default:break;
	}
	return cnt;
}
/*这样的走子 对方下局的行动力*/
int YcanWalkNext(int Ycolor, int x, int y, int option, int Map[][COL])
{
	int copyMap[ROW][COL] = { 0 };
	memcpy(copyMap, Map, sizeof(Map));
	ChangeMap(3 - Ycolor, x, y, option, copyMap);

	int walk_num = 0;

	for (int i = 2; i < 14; ++i)
	{
		for (int j = 2; j < 14; ++j)
		{
			if (copyMap[i][j] == Ycolor)
			{
				for (int op = UP; op <= DOWN_RIGHT; ++op)
				{
					if (canWalk(i, j, op, copyMap))
					{
						walk_num++;
					}
				}
			}
		}
	}

	return walk_num;
}
/*这样的走子 我方和对方下局的凝聚力*/
void cohesionNext(int Mcolor, int x, int y, int option, int Map[][COL],
	int *Mcohesion,int *Ycohesion)
{
	int copyMap[ROW][COL] = { 0 };
	memcpy(copyMap, Map, sizeof(Map));
	ChangeMap(Mcolor, x, y, option, copyMap);

	*Mcohesion = Cohesion(Mcolor, copyMap);
	*Ycohesion = Cohesion(3 - Mcolor, copyMap);
}
/*这样的走子 我方和对方下局的棋盘值*/
void mapvalueNext(int Mcolor, int x, int y, int option, int Map[][COL],
	int *Mmapvalue_next, int *Ymapvalue_next)
{
	int copyMap[ROW][COL] = { 0 };
	memcpy(copyMap, Map, sizeof(Map));
	ChangeMap(Mcolor, x, y, option, copyMap);

	*Mmapvalue_next = MapValue(Mcolor, Map);
	*Ymapvalue_next = MapValue(3-Mcolor, Map);
}





/*最高层的函数  用来寻找下一步的落子位置和方向*/
void FindNext(int Mcolor, int Map[][COL],int *Nextx,int *Nexty,int *Nextoption)
{
	LinkList list;
	CreateLink(&list);

	Chess buf;

	for (int i = 2; i < 14; ++i)
	{
		for (int j = 2; j < 14; ++j)
		{
			if (Map[i][j] == Mcolor)
			{
				for (int option = UP; option <= DOWN_RIGHT; ++option)
				{
					if (canWalk(i, j, option, Map))
					{
						buf.option = option;
						buf.x = i; buf.y = j;

						buf.nip_num = NipNum(3-Mcolor, i, j, option, Map);
						buf.pick_num = PickNum(3-Mcolor, i, j, option, Map);
						buf.Ywalk_next = YcanWalkNext(3 - Mcolor, i, j, option, Map);
						cohesionNext(Mcolor, i, j, option, Map,
							&buf.Mcohesion_next, &buf.Ycohesion_next);
						mapvalueNext(Mcolor, i, j, option, Map,
							&buf.Mmapvalue_next, &buf.Ymapvalue_next);

						Push_back(&list, &buf);
					}
				}
			}
		}
	}

	FindMaxValue(&list, &buf);
	*Nextx = buf.x;
	*Nexty = buf.y;
	*Nextoption = buf.option;

	ChangeMap(Mcolor, *Nextx, *Nexty, *Nextoption, Map);

	DestroyLink(&list);
}




int main(void)
{
	char OpCode[5] = { 0 };
	int FIELD;
	int Mcolor = 0, Ycolor = 0;
	int x, y, option;

	int Map[ROW][COL] = { 0 };
	Map[4][4] = Map[4][5] = Map[4][6] = Map[8][8] = Map[8][9] = Map[8][10] = Map[10][4] = Map[11][4] = WHITE;
	Map[7][5] = Map[7][6] = Map[7][7] = Map[11][9] = Map[11][10] = Map[11][11] = Map[4][11] = Map[5][11] = BLACK;

	while (1)
	{
		scanf("%s", OpCode);
		if (OpCode[0] == 'E')
		{
			scanf("%d", &FIELD);
			break;
		}
		else if (OpCode[0] == 'S')
		{
			scanf("%d", &FIELD);
			Mcolor = FIELD;
			Ycolor = 3 - Mcolor;
			printf("OK\n");
			fflush(stdout);
		}
		else if (OpCode[0] == 'P')
		{
			scanf("%d %d %d", &x, &y, &option);
			setMap(Ycolor, x+2, y+2, option, Map);	//增加两行两列
		}
		else if (OpCode[0] == 'T')
		{
			FindNext(Mcolor, Map, &x, &y, &option);
			printf("%d %d %d\n", x-2, y-2, option);		//消除掉多加的两行两列
			fflush(stdout);
			setMap(Mcolor, x, y, option, Map);		//setMap()不用加一,这个Map就是我自己包了一圈的Map
		}
		getchar();

		//showMap(Map);
	}

	system("pause");
	return 0;
}