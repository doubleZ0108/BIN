#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

enum{false,true};
typedef int bool;

//棋盘大小(包裹一圈)
#define ROW 14
#define COL 14
//棋子颜色
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

void showMap(int Map[][COL])
{
	printf("****************************************\n");
	printf("\x20\x20\x20");
	for (int i = 1; i < 13; ++i)
	{
		printf("%3d", i-1);
	}
	printf("\n");
	for (int i = 1; i < 13; ++i)
	{
		printf("%3d", i-1);
		for (int j = 1; j < 13; ++j)
		{
			printf("%3d", Map[i][j]);
		}
		printf("\n");
	}

	printf("****************************************\n");
}
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
	Map[x][y] = 0;
}
void FindNext(int Map[][COL],int Nextx,int Nexty,int Nextoption)
{

}
int main(void)
{
	char OpCode[5] = { 0 };
	int FIELD;
	int Mcolor = 0, Ycolor = 0;
	int x, y, option;

	int Map[ROW][COL] = { 0 };
	Map[3][3] = Map[3][4] = Map[3][5] = Map[7][7] = Map[7][8] = Map[7][9] = Map[9][3] = Map[10][3] = WHITE;
	Map[6][4] = Map[6][5] = Map[6][6] = Map[10][8] = Map[10][9] = Map[10][10] = Map[3][10] = Map[4][10] = BLACK;

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
			setMap(Ycolor, x+1, y+1, option, Map);	//增加一行一列
		}
		else if (OpCode[0] == 'T')
		{
			FindNext(Map, x, y, option);
			printf("%d %d %d\n", x-1, y-1, option);		//消除掉多加的一行一列
			fflush(stdout);
			setMap(Mcolor, x-1, y-1, option, Map);
		}
		getchar();

		showMap(Map);
	}

	system("pause");
	return 0;
}