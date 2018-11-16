#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>

#define U 0.1
#define V 0.053
#define N 50
HANDLE hConsole;
char lessismore[10] = { 'l','e','s','s','i','s','m','o','r','e' };
#define stoptimeshort  200
#define stoptimelong   500

void SetColor(unsigned short ForeColor, unsigned short BackGroundColor)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, (ForeColor % 16) | (BackGroundColor % 16 * 16));
}
void First_LineByLine(void)
{
	int i, s = 0, t, a = 10, b = 11, c = 12, d = 13, e = 14;
	int z[] = { 32,32,206,210,207,178,187,182,196,227,33,32,32 };
	float x, y;
	srand(time(NULL));

	for (y = 1.3; y >= -1.1; y -= U)
	{
		for (x = -2; x<1.4; x += V)
		{
			if ((((x*x + y * y - 1)*(x*x + y * y - 1)*(x*x + y * y - 1) - x * x*y*y*y) <= 0))
			{
				if (y >= 1.3 - 10 * U || y <= 1.3 - 11 * U)
				{
					s++;
					if (s % 4 == 1) { SetColor(a, 0); printf("l"); }
					if (s % 4 == 2) { SetColor(e, 0); printf("o"); }
					if (s % 4 == 3) { SetColor(c, 0); printf("v"); }
					if (s % 4 == 0) { SetColor(d, 0); printf("e"); }
				}
				else
				{
					for (i = 0; i < 42; i++)
					{
						if (i <= 14 || i >= 28)
						{
							s++;
							if (s % 4 == 1) { SetColor(a, 0); printf("l"); }
							if (s % 4 == 2) { SetColor(e, 0); printf("o"); }
							if (s % 4 == 3) { SetColor(c, 0); printf("v"); }
							if (s % 4 == 0) { SetColor(d, 0); printf("e"); }
						}
						else
						{
							SetColor(b, 0);
							printf("%c", z[i - 15]);
							Sleep(50);
						}
					}
					break;
				}
			}
			else
				printf(" ");
			Sleep(1);
		}
		printf("\n");
	}
	system("cls");
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hConsole, coord);
}
void Second_lessismore(void)
{
	int i, j, k;
	int now = 0;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(4, 6);
	for (i = 0; i<11; i++)
	{
		printf("%c", lessismore[now % 10]); now++;
		Sleep(N);
	}
	for (i = 0; i<12; i++)
	{
		gotoxy(9, 7 + i);
		printf("%c", lessismore[now % 10]); now++;
		Sleep(N);
	}
	gotoxy(4, 18);
	for (i = 0; i<11; i++)
	{
		printf("%c", lessismore[now % 10]); now++;
		Sleep(N);
	}
	gotoxy(36, 10);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	gotoxy(25, 10);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	gotoxy(47, 10);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	gotoxy(34, 8);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	gotoxy(38, 8);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	gotoxy(30, 7);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	gotoxy(42, 7);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	gotoxy(27, 8);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	gotoxy(45, 8);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	gotoxy(25, 11);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	gotoxy(47, 11);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	for (i = 1, j = 1; i<6, j<6; i++, j++)
	{
		gotoxy(25 + i, 11 + j);
		printf("%c", lessismore[now % 10]); now++;
		Sleep(N);
	}
	gotoxy(32, 17);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	gotoxy(34, 18);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	for (i = 1, j = 1; i<6, j<6; i++, j++)
	{
		gotoxy(47 - i, 11 + j);
		printf("%c", lessismore[now % 10]); now++;
		Sleep(N);
	}
	gotoxy(40, 17);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	gotoxy(38, 18);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	gotoxy(36, 19);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	for (i = 0; i<11; i++)
	{
		gotoxy(59, 6 + i);
		printf("%c", lessismore[now % 10]); now++;
		Sleep(N);
	}
	gotoxy(61, 17);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	for (i = 0; i<11; i++)
	{
		gotoxy(63 + i, 18);
		printf("%c", lessismore[now % 10]); now++;
		Sleep(N);
	}
	gotoxy(74, 17);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	gotoxy(76, 16);
	printf("%c", lessismore[now % 10]); now++;
	Sleep(N);
	for (i = 0; i<10; i++)
	{
		gotoxy(76, 15 - i);
		printf("%c", lessismore[now % 10]); now++;
		Sleep(N);
	}
	system("cls");
}

void Third_article(void)
{
	//////////////////
	char ch[10];
	int f[9][36] = { 0,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,
		0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,
		0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,
		0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,
		0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,
		0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,
		0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,
		0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,
		0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0
	};
	int s[9][21] = { 0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,
		0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,1,0,
		1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,
		0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,
		0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,
		0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,
		0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,
	};
	int t[9][22] = { 0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,
		0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,
		1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
		0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
		0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,
		0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,
		0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,
		0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
	};
	//////////////////
	//也许
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "也");
	Sleep(stoptimeshort);
	printf("%s", "许\n");
	////////////////////////////////
	//你还不知道我 我也不知道你
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "你");
	Sleep(stoptimeshort);
	printf("%s", "还");
	Sleep(stoptimeshort);
	printf("%s", "不");
	Sleep(stoptimeshort);
	printf("%s", "知");
	Sleep(stoptimeshort);
	printf("%s", "道");
	Sleep(stoptimeshort);
	printf("%s", "我\n");
	Sleep(stoptimeshort);

	printf("%s", "        ");
	Sleep(stoptimelong);

	printf("%s", "我");
	Sleep(stoptimeshort);
	printf("%s", "也");
	Sleep(stoptimeshort);
	printf("%s", "不");
	Sleep(stoptimeshort);
	printf("%s", "知");
	Sleep(stoptimeshort);
	printf("%s", "到");
	Sleep(stoptimeshort);
	printf("%s", "你\n");
	Sleep(stoptimeshort);
	///////////////////////////
	//但是
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "但");
	Sleep(stoptimeshort);
	printf("%s", "是\n");
	///////////////////////////
	//从我第一次见到你
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "从");
	Sleep(stoptimeshort);
	printf("%s", "我");
	Sleep(stoptimeshort);
	printf("%s", "第");
	Sleep(stoptimeshort);
	printf("%s", "一");
	Sleep(stoptimeshort);
	printf("%s", "次");
	Sleep(stoptimeshort);
	printf("%s", "见");
	Sleep(stoptimeshort);
	printf("%s", "到");
	Sleep(stoptimeshort);
	printf("%s", "你\n");
	/////////////////////////////
	//就有种说不出的感觉
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "就");
	Sleep(stoptimeshort);
	printf("%s", "有");
	Sleep(stoptimeshort);
	printf("%s", "种");
	Sleep(stoptimeshort);
	printf("%s", "说");
	Sleep(stoptimeshort);
	printf("%s", "不");
	Sleep(stoptimeshort);
	printf("%s", "出");
	Sleep(stoptimeshort);
	printf("%s", "的");
	Sleep(stoptimeshort);
	printf("%s", "感");
	Sleep(stoptimeshort);
	printf("%s", "觉\n");
	///////////////////////////////
	//有种似曾相识的熟悉
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "有");
	Sleep(stoptimeshort);
	printf("%s", "种");
	Sleep(stoptimeshort);
	printf("%s", "似");
	Sleep(stoptimeshort);
	printf("%s", "曾");
	Sleep(stoptimeshort);
	printf("%s", "相");
	Sleep(stoptimeshort);
	printf("%s", "识");
	Sleep(stoptimeshort);
	printf("%s", "的");
	Sleep(stoptimeshort);
	printf("%s", "熟");
	Sleep(stoptimeshort);
	printf("%s", "悉\n");
	///////////////////////////////
	//于是
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "于");
	Sleep(stoptimeshort);
	printf("%s", "是\n");
	//////////////////////////////
	//能看到你的每一天都感觉是最有趣的一天
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "能");
	Sleep(stoptimeshort);
	printf("%s", "看");
	Sleep(stoptimeshort);
	printf("%s", "到");
	Sleep(stoptimeshort);
	printf("%s", "你");
	Sleep(stoptimeshort);
	printf("%s", "的");
	Sleep(stoptimeshort);
	printf("%s", "每");
	Sleep(stoptimeshort);
	printf("%s", "一");
	Sleep(stoptimeshort);
	printf("%s", "天");
	Sleep(stoptimeshort);
	printf("%s", "都");
	Sleep(stoptimeshort);
	printf("%s", "感");
	Sleep(stoptimeshort);
	printf("%s", "觉");
	Sleep(stoptimeshort);
	printf("%s", "是");
	Sleep(stoptimeshort);
	printf("%s", "最");
	Sleep(stoptimeshort);
	printf("%s", "有");
	Sleep(stoptimeshort);
	printf("%s", "趣");
	Sleep(stoptimeshort);
	printf("%s", "的");
	Sleep(stoptimeshort);
	printf("%s", "一");
	Sleep(stoptimeshort);
	printf("%s", "天\n");
	///////////////////////////////
	//于是
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "于");
	Sleep(stoptimeshort);
	printf("%s", "是\n");
	///////////////////////////////
	//十四号楼
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "十");
	Sleep(stoptimeshort);
	printf("%s", "四");
	Sleep(stoptimeshort);
	printf("%s", "号");
	Sleep(stoptimeshort);
	printf("%s", "楼\n");
	///////////////////////////////
	//图书馆九楼
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "图");
	Sleep(stoptimeshort);
	printf("%s", "书");
	Sleep(stoptimeshort);
	printf("%s", "馆");
	Sleep(stoptimeshort);
	printf("%s", "九");
	Sleep(stoptimeshort);
	printf("%s", "楼\n");
	///////////////////////////////
	//周三广楼的雨伞
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "周");
	Sleep(stoptimeshort);
	printf("%s", "三");
	Sleep(stoptimeshort);
	printf("%s", "广");
	Sleep(stoptimeshort);
	printf("%s", "楼");
	Sleep(stoptimeshort);
	printf("%s", "的");
	Sleep(stoptimeshort);
	printf("%s", "雨");
	Sleep(stoptimeshort);
	printf("%s", "伞\n");
	///////////////////////////////
	//周三下午A207
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "周");
	Sleep(stoptimeshort);
	printf("%s", "三");
	Sleep(stoptimeshort);
	printf("%s", "下");
	Sleep(stoptimeshort);
	printf("%s", "午");
	Sleep(stoptimeshort);
	printf("%s", "A207\n");
	///////////////////////////////
	//我们每天都在遇见
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "我");
	Sleep(stoptimeshort);
	printf("%s", "们");
	Sleep(stoptimeshort);
	printf("%s", "每");
	Sleep(stoptimeshort);
	printf("%s", "天");
	Sleep(stoptimeshort);
	printf("%s", "都");
	Sleep(stoptimeshort);
	printf("%s", "在");
	Sleep(stoptimeshort);
	printf("%s", "遇");
	Sleep(stoptimeshort);
	printf("%s", "见\n");
	///////////////////////////////
	//只是
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "只");
	Sleep(stoptimeshort);
	printf("%s", "是\n");
	///////////////////////////////
	//老天让你等
	printf("\n");
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "老");
	Sleep(stoptimeshort);
	printf("%s", "天");
	Sleep(stoptimeshort);
	printf("%s", "让");
	Sleep(stoptimeshort);
	printf("%s", "你");
	Sleep(stoptimeshort);
	printf("%s", "等\n");
	///////////////////////////////
	//是为了让你等到对的那个人
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "是");
	Sleep(stoptimeshort);
	printf("%s", "为");
	Sleep(stoptimeshort);
	printf("%s", "了");
	Sleep(stoptimeshort);
	printf("%s", "让");
	Sleep(stoptimeshort);
	printf("%s", "你");
	Sleep(stoptimeshort);
	printf("%s", "等");
	Sleep(stoptimeshort);
	printf("%s", "到");
	Sleep(stoptimeshort);
	printf("%s", "对");
	Sleep(stoptimeshort);
	printf("%s", "的");
	Sleep(stoptimeshort);
	printf("%s", "那");
	Sleep(stoptimeshort);
	printf("%s", "个");
	Sleep(stoptimeshort);
	printf("%s", "人\n");
	///////////////////////////////
	//于小姐
	printf("\n");
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "于");
	Sleep(stoptimeshort);
	printf("%s", "小");
	Sleep(stoptimeshort);
	printf("%s", "姐\n");
	///////////////////////////////
	//别等了
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "别");
	Sleep(stoptimeshort);
	printf("%s", "等");
	Sleep(stoptimeshort);
	printf("%s", "了\n");
	///////////////////////////////
	//less is more
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "l");
	Sleep(stoptimeshort);
	printf("%s", "e");
	Sleep(stoptimeshort);
	printf("%s", "s");
	Sleep(stoptimeshort);
	printf("%s", "s\x20");
	Sleep(stoptimeshort);
	printf("%s", "i");
	Sleep(stoptimeshort);
	printf("%s", "s\x20");
	Sleep(stoptimeshort);
	printf("%s", "m");
	Sleep(stoptimeshort);
	printf("%s", "o");
	Sleep(stoptimeshort);
	printf("%s", "r");
	Sleep(stoptimeshort);
	printf("%s", "e\n");
	///////////////////////////////
	//未来你会遇到许多有趣的人和事
	printf("\n");
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "未");
	Sleep(stoptimeshort);
	printf("%s", "来");
	Sleep(stoptimeshort);
	printf("%s", "你");
	Sleep(stoptimeshort);
	printf("%s", "会");
	Sleep(stoptimeshort);
	printf("%s", "遇");
	Sleep(stoptimeshort);
	printf("%s", "到");
	Sleep(stoptimeshort);
	printf("%s", "许");
	Sleep(stoptimeshort);
	printf("%s", "多");
	Sleep(stoptimeshort);
	printf("%s", "有");
	Sleep(stoptimeshort);
	printf("%s", "趣");
	Sleep(stoptimeshort);
	printf("%s", "的");
	Sleep(stoptimeshort);
	printf("%s", "人");
	Sleep(stoptimeshort);
	printf("%s", "和");
	Sleep(stoptimeshort);
	printf("%s", "事\n");
	///////////////////////////////
	//今天也是
	printf("%s", "        ");
	Sleep(stoptimelong);
	printf("%s", "今");
	Sleep(stoptimeshort);
	printf("%s", "天");
	Sleep(stoptimeshort);
	printf("%s", "也");
	Sleep(stoptimeshort);
	printf("%s", "是\n");
	Sleep(stoptimelong);
}

int main(void)
{
	system("title less_is_more@163.com");

	First_LineByLine();
	Second_lessismore();
	Third_article();


	system("pause");
	return 0;
}