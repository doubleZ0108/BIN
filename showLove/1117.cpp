
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

int main(void)
{
	First_LineByLine();
	Second_lessismore();

	system("pause");
	return 0;
}