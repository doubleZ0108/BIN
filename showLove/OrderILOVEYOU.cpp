#include <stdio.h>
#include <windows.h>
#define N 50
HANDLE hConsole;
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hConsole, coord);
}
char lessismore[10] = { 'l','e','s','s','i','s','m','o','r','e' };

int main()
{
	int i, j, k;
	int now = 0;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	for (k = 0; k<3; k++)
	{
		gotoxy(4, 6);
		for (i = 0; i<11; i++)
		{
			printf("%c",lessismore[now%10]);now++;
			Sleep(N);
		}
		for (i = 0; i<12; i++)
		{
			gotoxy(9, 7 + i);
			printf("%c",lessismore[now%10]);now++;
			Sleep(N);
		}
		gotoxy(4, 18);
		for (i = 0; i<11; i++)
		{
			printf("%c",lessismore[now%10]);now++;
			Sleep(N);
		}
		gotoxy(36, 10);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		gotoxy(25, 10);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		gotoxy(47, 10);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		gotoxy(34, 8);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		gotoxy(38, 8);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		gotoxy(30, 7);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		gotoxy(42, 7);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		gotoxy(27, 8);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		gotoxy(45, 8);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		gotoxy(25, 11);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		gotoxy(47, 11);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		for (i = 1, j = 1; i<6, j<6; i++, j++)
		{
			gotoxy(25 + i, 11 + j);
			printf("%c",lessismore[now%10]);now++;
			Sleep(N);
		}
		gotoxy(32, 17);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		gotoxy(34, 18);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		for (i = 1, j = 1; i<6, j<6; i++, j++)
		{
			gotoxy(47 - i, 11 + j);
			printf("%c",lessismore[now%10]);now++;
			Sleep(N);
		}
		gotoxy(40, 17);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		gotoxy(38, 18);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		gotoxy(36, 19);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		for (i = 0; i<11; i++)
		{
			gotoxy(59, 6 + i);
			printf("%c",lessismore[now%10]);now++;
			Sleep(N);
		}
		gotoxy(61, 17);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		for (i = 0; i<11; i++)
		{
			gotoxy(63 + i, 18);
			printf("%c",lessismore[now%10]);now++;
			Sleep(N);
		}
		gotoxy(74, 17);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		gotoxy(76, 16);
		printf("%c",lessismore[now%10]);now++;
		Sleep(N);
		for (i = 0; i<10; i++)
		{
			gotoxy(76, 15 - i);
			printf("%c",lessismore[now%10]);now++;
			Sleep(N);
		}
		system("cls");
	}
	

	system("pause");
	return 0;
}
