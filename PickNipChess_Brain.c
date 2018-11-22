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

#define RET_EAT      0
#define RET_WALKNUM  0
#define RET_COHESION 1			//凝聚力nice
#define RET_POSVALUE 0

/////////////////////////////////////
#define RET_CENTRA   1

#define YY 0
#define AA 1
#define BB 2
#define CC 3
#define DD 4
int POSVALUE[ROW][COL] =
{
	YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,
	YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,YY,
	YY,YY,AA,AA,AA,BB,BB,CC,CC,BB,BB,AA,AA,AA,YY,YY,
	YY,YY,AA,AA,BB,BB,CC,CC,CC,CC,BB,BB,AA,AA,YY,YY,
	YY,YY,AA,BB,BB,CC,CC,CC,CC,CC,CC,BB,BB,AA,YY,YY,
	YY,YY,BB,BB,CC,CC,CC,DD,DD,CC,CC,CC,BB,BB,YY,YY,
	YY,YY,BB,CC,CC,CC,DD,DD,DD,DD,CC,CC,CC,BB,YY,YY,
	YY,YY,CC,CC,CC,DD,DD,DD,DD,DD,DD,CC,CC,CC,YY,YY,//
	YY,YY,CC,CC,CC,DD,DD,DD,DD,DD,DD,CC,CC,CC,YY,YY,//
	YY,YY,BB,CC,CC,CC,DD,DD,DD,DD,CC,CC,CC,BB,YY,YY,
	YY,YY,BB,BB,CC,CC,CC,DD,DD,CC,CC,CC,BB,BB,YY,YY,
	YY,YY,AA,BB,BB,CC,CC,CC,CC,CC,CC,BB,BB,AA,YY,YY,
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
	//int pick_num, nip_num;	//走当前步可以挑吃和夹持的数量

	int Meatnum_next;
	int Yeatnum_next;

	int Mwalknum_next;
	int Ywalknum_next;			//对方下局的行动力

	int Mcohesion_next;			//我方的凝聚力
	int Ycohesion_next;			//对方的凝聚力

	int Mmapvalue_next;				//棋盘位置值
	int Ymapvalue_next;


	///////////////////////////////////
	int centra_next;			//是否向中间集中
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
	list->head->next = NULL;
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

/*输出所有可以的移动方式的参数列表*/
void showList(const LinkList *list)
{
	struct NODE *move = list->head->next;

	for (; move != NULL; move = move->next)
	{
		printf("(%d,%d)[%d]", move->data.x, move->data.y, move->data.option);
		//printf(" cohesion is %d - %d\n", move->data.Mcohesion_next,move->data.Ycohesion_next);
		//printf("walknum is %d - %d\n", move->data.Mwalknum_next, move->data.Ywalknum_next);
		printf("centra is %d\n", move->data.centra_next);
	}
}


/*随机落子√*/
void RandFind(LinkList *list, Chess *save)
{
	*save = list->head->next->data;
	struct NODE *move = list->head->next;
	srand(time(NULL));
	int sum = 0;
	for (; move != NULL; move = move->next)
	{
		sum++;
	}

	int cnt = rand() % (sum - 1);
	sum = 0;
	for (move = list->head->next; move != NULL; move = move->next)
	{
		sum++;
		if (sum == cnt)
		{
			*save = move->data;
		}
	}
}
/*寻找价值和最大的走法*/
void FindMaxValue(LinkList *list, Chess *save)
{
	struct NODE *move = list->head->next;
	int maxvalue =
		//(move->data.nip_num + move->data.pick_num)*RET_EAT
		+move->data.centra_next*RET_CENTRA
		+(move->data.Meatnum_next - move->data.Yeatnum_next)*RET_EAT
		+ (move->data.Mwalknum_next - move->data.Ywalknum_next)*RET_WALKNUM
		+ (move->data.Mcohesion_next - move->data.Ycohesion_next)*RET_COHESION
		+ (move->data.Mmapvalue_next - move->data.Ymapvalue_next)*RET_POSVALUE;


	Chess buf = move->data;

	int bufvalue;

	for (move = move->next; move != NULL; move = move->next)
	{
		bufvalue =
			//(move->data.nip_num + move->data.pick_num)*RET_EAT
			+move->data.centra_next*RET_CENTRA
			+ (move->data.Meatnum_next - move->data.Yeatnum_next)*RET_EAT
			+ (move->data.Mwalknum_next - move->data.Ywalknum_next)*RET_WALKNUM
			+ (move->data.Mcohesion_next - move->data.Ycohesion_next)*RET_COHESION
			+ (move->data.Mmapvalue_next - move->data.Ymapvalue_next)*RET_POSVALUE;

		if (bufvalue > maxvalue)
		{
			maxvalue = bufvalue;

			buf = move->data;
		}
	}

	*save = buf;
}

////////////////////////////////////////////


/*显示整个棋盘√*/
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
/*移动某方棋子√*/		//不做任何检测
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
/*某方向是否可走√*/
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


////////////////////////////////////////////
/*挑吃√*/
void PickChess(int Ycolor, int x, int y, int option, int Map[][COL])
{
	switch (option)
	{
	case UP:
	{
		if (Map[x - 1][y - 1] == Ycolor && Map[x - 1][y + 1] == Ycolor) {
			Map[x - 1][y - 1] = Map[x - 1][y + 1] = 3 - Ycolor;
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
}
/*夹吃√*/
void NipChess(int Ycolor, int x, int y, int option, int Map[][COL])
{
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
		if (Map[x - 1][y + 1] == Ycolor && Map[x - 1][y + 2] == 3 - Ycolor) {
			Map[x - 1][y + 1] = 3 - Ycolor;
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
		if (Map[x + 1][y - 1] == Ycolor && Map[x + 1][y - 2] == 3 - Ycolor) {
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
		if (Map[x + 1][y] == Ycolor && Map[x + 2][y - 1] == 3 - Ycolor) {
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
		if (Map[x][y - 2] == Ycolor && Map[x + 1][y - 3] == 3 - Ycolor) {
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
}

/*我走子之后调整棋盘√*/
void ChangeMap(int color, int x, int y, int option, int Map[][COL])
{
	PickChess(3 - color, x, y, option, Map);
	NipChess(3 - color, x, y, option, Map);
}
////////////////////////////////////////////


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
						if (Map[i + a][j + b] == color)
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
				mapvalue += POSVALUE[i][j];
			}
		}
	}

	return mapvalue;
}
/*color方的行动力*/
int WalkNum(int color, int Map[][COL])
{
	int walk_num = 0;

	for (int i = 2; i < 14; ++i)
	{
		for (int j = 2; j < 14; ++j)
		{
			if (Map[i][j] == color)
			{
				for (int op = UP; op <= DOWN_RIGHT; ++op)
				{
					if (canWalk(i, j, op, Map))
					{
						walk_num++;
					}
				}
			}
		}
	}

	return walk_num;
}


/*这样的走子 我方挑吃个数√*/
int PickNum(int Ycolor, int x, int y, int option, int Map[][COL])
{
	int cnt = 0;

	switch (option)
	{
	case UP:
	{
		if (Map[x - 1][y - 1] == Ycolor && Map[x - 1][y + 1] == Ycolor) {
			cnt += 2;
		}
		if (Map[x - 2][y - 1] == Ycolor && Map[x][y + 1] == Ycolor) {
			cnt += 2;
		}
		if (Map[x][y - 1] == Ycolor && Map[x - 2][y + 1] == Ycolor) {
			cnt += 2;
		}

		break;
	}
	case DOWN:
	{
		if (Map[x + 1][y - 1] == Ycolor && Map[x + 1][y + 1] == Ycolor) {
			cnt += 2;
		}
		if (Map[x][y - 1] == Ycolor && Map[x + 2][y + 1] == Ycolor) {
			cnt += 2;
		}
		if (Map[x + 2][y - 1] == Ycolor && Map[x][y + 1] == Ycolor) {
			cnt += 2;
		}

		break;
	}
	case LEFT:
	{
		if (Map[x - 1][y - 1] == Ycolor && Map[x + 1][y - 1] == Ycolor) {
			cnt += 2;
		}
		if (Map[x - 1][y - 2] == Ycolor && Map[x + 1][y] == Ycolor) {
			cnt += 2;
		}
		if (Map[x + 1][y - 2] == Ycolor && Map[x - 1][y] == Ycolor) {
			cnt += 2;
		}

		break;
	}
	case RIGHT:
	{
		if (Map[x - 1][y + 1] == Ycolor && Map[x + 1][y + 1] == Ycolor) {
			cnt += 2;
		}
		if (Map[x - 1][y] == Ycolor && Map[x + 1][y + 2] == Ycolor) {
			cnt += 2;
		}
		if (Map[x + 1][y] == Ycolor && Map[x - 1][y + 2] == Ycolor) {
			cnt += 2;
		}

		break;
	}
	case UP_LEFT:
	{
		if (Map[x - 2][y - 1] == Ycolor && Map[x][y - 1] == Ycolor) {
			cnt += 2;
		}
		if (Map[x - 1][y - 2] == Ycolor && Map[x - 1][y] == Ycolor) {
			cnt += 2;
		}
		if (Map[x][y - 2] == Ycolor && Map[x - 2][y] == Ycolor) {
			cnt += 2;
		}

		break;
	}
	case UP_RIGHT:
	{
		if (Map[x - 2][y + 1] == Ycolor && Map[x][y + 1] == Ycolor) {
			cnt += 2;
		}
		if (Map[x - 2][y] == Ycolor && Map[x][y + 2] == Ycolor) {
			cnt += 2;
		}
		if (Map[x - 1][y] == Ycolor && Map[x - 1][y + 2] == Ycolor) {
			cnt += 2;
		}

		break;
	}
	case DOWN_LEFT:
	{
		if (Map[x][y - 1] == Ycolor && Map[x + 2][y - 1] == Ycolor) {
			cnt += 2;
		}
		if (Map[x + 1][y - 2] == Ycolor && Map[x + 1][y] == Ycolor) {
			cnt += 2;
		}
		if (Map[x][y - 2] == Ycolor && Map[x + 2][y] == Ycolor) {
			cnt += 2;
		}

		break;
	}
	case DOWN_RIGHT:
	{
		if (Map[x][y + 1] == Ycolor && Map[x + 2][y + 1] == Ycolor) {
			cnt += 2;
		}
		if (Map[x + 1][y] == Ycolor && Map[x + 1][y + 2] == Ycolor) {
			cnt += 2;
		}
		if (Map[x + 2][y] == Ycolor && Map[x][y + 2] == Ycolor) {
			cnt += 2;
		}

		break;
	}
	default:break;
	}


	return cnt;
}
/*这样的走子 我方夹吃个数√*/
int NipNum(int Ycolor, int x, int y, int option, int Map[][COL])
{
	int cnt = 0;
	switch (option)
	{
	case UP:
	{
		if (Map[x - 2][y - 1] == Ycolor && Map[x - 3][y - 2] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x - 2][y] == Ycolor && Map[x - 3][y] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x - 2][y + 1] == Ycolor && Map[x - 3][y + 2] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x - 1][y - 1] == Ycolor && Map[x - 1][y - 2] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x - 1][y + 1] == Ycolor && Map[x - 1][y + 2] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x][y - 1] == Ycolor && Map[x + 1][y - 2] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x][y + 1] == Ycolor && Map[x + 1][y + 2] == 3 - Ycolor) {
			cnt++;
		}

		break;
	}
	case DOWN:
	{
		if (Map[x][y - 1] == Ycolor && Map[x - 1][y - 2] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x][y + 1] == Ycolor && Map[x - 1][y + 2] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 1][y - 1] == Ycolor && Map[x + 1][y - 2] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 1][y + 1] == Ycolor && Map[x + 1][y + 2] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 2][y - 1] == Ycolor && Map[x + 3][y - 2] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 2][y] == Ycolor && Map[x + 3][y] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 2][y + 1] == Ycolor && Map[x + 3][y + 2] == 3 - Ycolor) {
			cnt++;
		}

		break;
	}
	case LEFT:
	{
		if (Map[x - 1][y - 2] == Ycolor && Map[x - 2][y - 3] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x - 1][y - 1] == Ycolor && Map[x - 2][y - 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x - 1][y] == Ycolor && Map[x - 2][y + 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x][y - 2] == Ycolor && Map[x][y - 3] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 1][y - 2] == Ycolor && Map[x + 2][y - 3] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 1][y - 1] == Ycolor && Map[x + 2][y - 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 1][y] == Ycolor && Map[x + 2][y + 1] == 3 - Ycolor) {
			cnt++;
		}

		break;
	}
	case RIGHT:
	{
		if (Map[x - 1][y] == Ycolor && Map[x - 2][y - 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x - 1][y + 1] == Ycolor && Map[x - 2][y + 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x - 1][y + 2] == Ycolor && Map[x - 2][y + 3] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x][y + 2] == Ycolor && Map[x][y + 3] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 1][y] == Ycolor && Map[x + 2][y - 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 1][y + 1] == Ycolor && Map[x + 2][y + 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 1][y + 2] == Ycolor && Map[x + 2][y + 3] == 3 - Ycolor) {
			cnt++;
		}

		break;
	}
	case UP_LEFT:
	{
		if (Map[x - 2][y - 2] == Ycolor && Map[x - 3][y - 3] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x - 2][y - 1] == Ycolor && Map[x - 3][y - 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x - 2][y] == Ycolor && Map[x - 3][y + 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x - 1][y - 2] == Ycolor && Map[x - 1][y - 3] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x - 1][y] == Ycolor && Map[x - 1][y + 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x][y - 2] == Ycolor && Map[x + 1][y - 3] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x][y - 1] == Ycolor && Map[x + 1][y - 1] == 3 - Ycolor) {
			cnt++;
		}
		break;
	}
	case UP_RIGHT:
	{
		if (Map[x - 2][y] == Ycolor && Map[x - 3][y - 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x - 2][y + 1] == Ycolor && Map[x - 3][y + 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x - 2][y + 2] == Ycolor && Map[x - 3][y + 3] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x - 1][y] == Ycolor && Map[x - 1][y - 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x - 1][y + 2] == Ycolor && Map[x - 1][y + 3] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x][y + 1] == Ycolor && Map[x + 1][y + 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x][y + 2] == Ycolor && Map[x + 1][y + 3] == 3 - Ycolor) {
			cnt++;
		}

		break;
	}
	case DOWN_LEFT:
	{
		if (Map[x][y - 2] == Ycolor && Map[x - 1][y - 3] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x][y - 1] == Ycolor && Map[x - 1][y - 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 1][y - 2] == Ycolor && Map[x + 1][y - 3] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 1][y] == Ycolor && Map[x + 1][y + 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 2][y - 2] == Ycolor && Map[x + 3][y - 3] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 2][y - 1] == Ycolor && Map[x + 3][y - 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 2][y] == Ycolor && Map[x + 3][y + 1] == 3 - Ycolor) {
			cnt++;
		}

		break;
	}
	case DOWN_RIGHT:
	{
		if (Map[x][y + 1] == Ycolor && Map[x - 1][y + 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x][y + 2] == Ycolor && Map[x - 1][y + 3] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 1][y] == Ycolor && Map[x + 1][y - 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 1][y + 2] == Ycolor && Map[x + 1][y + 3] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 2][y] == Ycolor && Map[x + 3][y - 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 2][y + 1] == Ycolor && Map[x + 3][y + 1] == 3 - Ycolor) {
			cnt++;
		}
		if (Map[x + 2][y + 2] == Ycolor && Map[x + 3][y + 3] == 3 - Ycolor) {
			cnt++;
		}

		break;
	}
	default:break;
	}
	return cnt;
}


/*这样的走子 我方和对方下局的吃子数*/
void eatnumNext(int Mcolor, int x, int y, int option, int Map[][COL],
	int *Meatnum, int *Yeatnum)
{
	int copyMap[ROW][COL] = { 0 };
	memcpy(copyMap, Map, ROW*COL * sizeof(Map));

	*Meatnum = PickNum(3 - Mcolor, x, y, option, copyMap) + 
		NipNum(3 - Mcolor, x, y, option, copyMap);

	setMap(Mcolor, x, y, option, copyMap);
	ChangeMap(Mcolor, x, y, option, copyMap);

	*Yeatnum = 0;

	for (int i = 2; i < 14; ++i)
	{
		for (int j = 2; j < 14; ++j)
		{
			for (int choice = UP; choice <= DOWN_RIGHT; ++choice)
			{
				if (canWalk(i, j, choice, copyMap))
				{
					int saveEatNum = PickNum(Mcolor, i, j, choice, copyMap) +
						NipNum(Mcolor, i, j, choice, copyMap);

					if (saveEatNum > *Yeatnum)
					{
						*Yeatnum = saveEatNum;
					}
				}
			}
		}
	}
}
/*这样的走子 我方和对方下局的行动力*/
void walknumNext(int Mcolor, int x, int y, int option, int Map[][COL],
	int *Mcanwalk, int *Ycanwalk)
{
	int copyMap[ROW][COL] = { 0 };
	memcpy(copyMap, Map, ROW*COL*sizeof(Map));

	setMap(Mcolor, x, y, option, copyMap);
	ChangeMap(Mcolor, x, y, option, copyMap);

	*Mcanwalk = WalkNum(Mcolor, copyMap);
	*Ycanwalk = WalkNum(3 - Mcolor, copyMap);
}
/*这样的走子 我方和对方下局的凝聚力*/
void cohesionNext(int Mcolor, int x, int y, int option, int Map[][COL],
	int *Mcohesion,int *Ycohesion)
{
	int copyMap[ROW][COL] = { 0 };
	memcpy(copyMap, Map, ROW*COL*sizeof(Map));

	setMap(Mcolor, x, y, option, copyMap);
	ChangeMap(Mcolor, x, y, option, copyMap);

	*Mcohesion = Cohesion(Mcolor, copyMap);
	*Ycohesion = Cohesion(3 - Mcolor, copyMap);
}
/*这样的走子 我方和对方下局的棋盘值*/
void mapvalueNext(int Mcolor, int x, int y, int option, int Map[][COL],
	int *Mmapvalue_next, int *Ymapvalue_next)
{
	int copyMap[ROW][COL] = { 0 };
	memcpy(copyMap, Map, ROW*COL*sizeof(Map));

	setMap(Mcolor, x, y, option, copyMap);
	ChangeMap(Mcolor, x, y, option, copyMap);

	*Mmapvalue_next = MapValue(Mcolor, copyMap);
	*Ymapvalue_next = MapValue(3-Mcolor, copyMap);
}


bool ifcentra(int Mcolor, int x, int y, int option)
{
	if (x < 7 && y < 7)
	{
		return (option == DOWN || option == DOWN_RIGHT);
	}
	else if (x < 7 && y>8)
	{
		return (option == DOWN || option == DOWN_LEFT);
	}
	else if (x > 8 && y < 7)
	{
		return (option == UP || option == UP_RIGHT);
	}
	else if (x > 8 && y > 8)
	{
		return (option == UP || option == UP_LEFT);
	}
	else if ((x == 7 || x == 8) && y < 7)
	{
		return (option == RIGHT);
	}
	else if ((y == 7 || y == 8) && x < 7)
	{
		return (option == DOWN);
	}
	else if ((x == 7 || x == 8) && y > 8)
	{
		return (option == LEFT);
	}
	else if ((y == 7 || y == 8) && x > 8)
	{
		return (option == UP);
	}

	return false;
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

						/*buf.nip_num = NipNum(3-Mcolor, i, j, option, Map);
						buf.pick_num = PickNum(3-Mcolor, i, j, option, Map);*/

						eatnumNext(Mcolor, i, j, option, Map,
							&buf.Meatnum_next, &buf.Yeatnum_next);

						/////////////////////////////
						buf.centra_next = ifcentra(Mcolor, i, j, option);

						//////////////////////////////
						walknumNext(Mcolor, i, j, option, Map,
							&buf.Mwalknum_next, &buf.Ywalknum_next);

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

	/*printf("/////////////////////////////////\n");
	showList(&list);
	printf("/////////////////////////////////\n");
*/
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
			x += 2; y += 2;	//增加两行两列

			setMap(Ycolor, x, y, option, Map);

			ChangeMap(Ycolor, x, y, option, Map);
		}
		else if (OpCode[0] == 'T')
		{
			FindNext(Mcolor, Map, &x, &y, &option);

			printf("%d %d %d\n", x-2, y-2, option);		//消除掉多加的两行两列
			fflush(stdout);

			setMap(Mcolor, x, y, option, Map);		//setMap()不用加一,这个Map就是我自己包了一圈的Map
			ChangeMap(Mcolor, x, y, option, Map);
		}
		getchar();

		showMap(Map);
	}

	system("pause");
	return 0;
}