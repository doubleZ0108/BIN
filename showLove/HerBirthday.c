#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include<time.h>
#include <tchar.h>

HANDLE hConsole;
#define MaxSize 5
#define stoptimeshortshort 50
#define stoptimeshort  100
#define stoptimelong   500
#define stoptimelonglong   2000

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/*================= hello world ======================*/
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hConsole, coord);
}

void First_HelloWorld(void)
{
	char strhelloworld[13][6] = { { 208,161 },{ 199,201 },{ 193,225 },{ 231,231 },{ 195,212 },{ 196,227 },{ 191,201 },{ 176,174 },{ 181,196 },"160cm",{ 208,161 },{ 194,220 },{ 192,242 }, };
	printf("%s", "        ");
	for (int i = 0; i < 13; ++i)
	{
		Sleep(stoptimelong);
		printf("%s", strhelloworld[i]);
		Sleep(stoptimeshort);
	}
	printf("\n");
	system("cls");

	char happybirthday[13] = { 'h','a','p','p','y','b','i','r','t','h','d','a','y' };

	int i, j, k;
	int now = 0;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	gotoxy(4, 6);
	for (i = 0; i<11; i++)
	{
		printf("%c", happybirthday[now % 10]); now++;
		Sleep(stoptimeshortshort);
	}
	for (i = 0; i<12; i++)
	{
		gotoxy(9, 7 + i);
		printf("%c", happybirthday[now % 10]); now++;
		Sleep(stoptimeshortshort);
	}
	gotoxy(4, 18);
	for (i = 0; i<11; i++)
	{
		printf("%c", happybirthday[now % 10]); now++;
		Sleep(stoptimeshortshort);
	}
	gotoxy(36, 10);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	gotoxy(25, 10);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	gotoxy(47, 10);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	gotoxy(34, 8);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	gotoxy(38, 8);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	gotoxy(30, 7);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	gotoxy(42, 7);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	gotoxy(27, 8);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	gotoxy(45, 8);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	gotoxy(25, 11);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	gotoxy(47, 11);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	for (i = 1, j = 1; i<6, j<6; i++, j++)
	{
		gotoxy(25 + i, 11 + j);
		printf("%c", happybirthday[now % 10]); now++;
		Sleep(stoptimeshortshort);
	}
	gotoxy(32, 17);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	gotoxy(34, 18);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	for (i = 1, j = 1; i<6, j<6; i++, j++)
	{
		gotoxy(47 - i, 11 + j);
		printf("%c", happybirthday[now % 10]); now++;
		Sleep(stoptimeshortshort);
	}
	gotoxy(40, 17);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	gotoxy(38, 18);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	gotoxy(36, 19);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	for (i = 0; i<11; i++)
	{
		gotoxy(59, 6 + i);
		printf("%c", happybirthday[now % 10]); now++;
		Sleep(stoptimeshortshort);
	}
	gotoxy(61, 17);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	for (i = 0; i<11; i++)
	{
		gotoxy(63 + i, 18);
		printf("%c", happybirthday[now % 10]); now++;
		Sleep(stoptimeshortshort);
	}
	gotoxy(74, 17);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	gotoxy(76, 16);
	printf("%c", happybirthday[now % 10]); now++;
	Sleep(stoptimeshortshort);
	for (i = 0; i<10; i++)
	{
		gotoxy(76, 15 - i);
		printf("%c", happybirthday[now % 10]); now++;
		Sleep(stoptimeshortshort);
	}

	Sleep(stoptimelonglong);
	system("cls");
}

/*================= article ======================*/
void OutputMess(char *name, char (*str)[3], int size)
{
	setColor(name[1] == 'K' ? 6 : 3);
	printf("%s", name);

	Sleep(stoptimelong);
	for (int i = 0; i < size; ++i)
	{
		printf("%s", str[i]);
		Sleep(stoptimeshort);
	}
	printf("\n");
}

void Second_article(void)
{	
	char time[9][17] = { "2018-09-10 09:45","2018-10-26 09:05","2018-11-11 00:05","2018-11-11 18:08",
		"2018-11-23 15:31","2018-12-24 22:31","2019-01-01 00:00","2019-01-08 03:25","2019-02-12 18:14", };
	char *doubleZ = "[double Z]", *Kerr = "[Kerr]";

	for (int i = 0; i < 9; ++i)
	{
		setColor(7);
		system("cls");
		printf("%s\n", time[i]);

		switch (i)
		{
		case 0:
		{
			char str1[14][3] = { { 206,210 },{ 193,170 },{ 207,181 },{ 196,227 },{ 44,196 },{ 227,214 },{ 170,181 },{ 192,202 },{ 178,195 },{ 180,210 },{ 226,203 },{ 188,193 },{ 203,176 },{ 201,0 }, };
			OutputMess(doubleZ, str1, 14);
			char str2[2][3] = { { 185,253 },{ 193,203 }, };
			OutputMess(Kerr, str2, 2);
			char str3[11][3] = { { 185,167 },{ 207,178 },{ 196,227 },{ 188,211 },{ 200,235 },{ 215,233 },{ 214,175 },{ 178,191 },{ 180,243 },{ 188,210 },{ 205,165 }, };
			OutputMess(doubleZ, str3, 11);
			break;
		}
		case 1:
		{
			char str1[14][3] = { { 211,173 },{ 208,194 },{ 205,237 },{ 187,225 },{ 206,210 },{ 184,248 },{ 196,227 },{ 215,188 },{ 177,184 },{ 193,203 },{ 210,187 },{ 184,246 },{ 190,170 },{ 207,178 },};
			OutputMess(Kerr, str1, 14);
			char str2[5][3] = { { 199,235 },{ 177,163 },{ 179,214 },{ 186,195 },{ 198,230 }, };
			OutputMess(Kerr, str2, 5);
			char str3[13][3] = { { 176,165 },{ 209,189 },{ 206,210 },{ 213,226 },{ 184,246 },{ 200,203 },{ 190,205 },{ 202,199 },{ 178,216 },{ 178,187 },{ 215,161 },{ 190,170 },{ 207,178 }, };
			OutputMess(Kerr, str3, 13);
			break;
		}
		case 2:
		{
			char str1[14][3] = { { 196,227 },{ 211,208 },{ 207,235 },{ 185,253 },{ 196,227 },{ 215,212 },{ 188,186 },{ 213,230 },{ 181,196 },{ 207,178 },{ 187,182 },{ 203,251 },{ 195,180 },{ 63,0 }, };
			OutputMess(doubleZ, str1, 14);
			char str2[16][3] = { { 202,199 },{ 178,187 },{ 202,199 },{ 210,242 },{ 206,170 },{ 184,213 },{ 201,207 },{ 180,243 },{ 209,167 },{ 44,202 },{ 178,195 },{ 180,182 },{ 188,186 },{ 220,208 },{ 194,207 },{ 202,0 }, };
			OutputMess(doubleZ, str2, 16);
			char str3[14][3] = { { 196,227 },{ 178,187 },{ 190,245 },{ 181,195 },{ 210,187 },{ 199,208 },{ 183,162 },{ 201,250 },{ 181,196 },{ 204,171 },{ 191,236 },{ 193,203 },{ 195,180 },{ 63,0 }, };
			OutputMess(doubleZ, str3, 14);
			char str4[25][3] = { { 207,214 },{ 212,218 },{ 187,216 },{ 205,183 },{ 207,235 },{ 207,235 },{ 201,207 },{ 180,243 },{ 209,167 },{ 213,226 },{ 193,189 },{ 184,246 },{ 212,194 },{ 44,211 },{ 208,195 },{ 187,211 },{ 208,190 },{ 245,181 },{ 195,195 },{ 191,204 },{ 236,182 },{ 188,212 },{ 218,207 },{ 185,195 },{ 166,0 }, };
			OutputMess(doubleZ, str4, 25); 
			char str5[10][3] = { { 181,171 },{ 202,199 },{ 184,208 },{ 190,245 },{ 202,178 },{ 195,180 },{ 182,188 },{ 195,187 },{ 193,244 },{ 207,194 }, };
			OutputMess(doubleZ, str5, 10);

			printf("\n");
			char str6[17][3] = { { 196,227 },{ 214,170 },{ 181,192 },{ 206,252 },{ 182,190 },{ 181,196 },{ 200,203 },{ 206,170 },{ 202,178 },{ 195,180 },{ 187,225 },{ 181,195 },{ 210,214 },{ 211,244 },{ 214,162 },{ 194,240 },{ 63,0 }, };
			OutputMess(Kerr, str6, 17);
			char str7[20][3] = { { 210,242 },{ 206,170 },{ 206,252 },{ 182,190 },{ 181,196 },{ 191,236 },{ 192,214 },{ 186,205 },{ 205,163 },{ 207,194 },{ 192,180 },{ 186,243 },{ 181,196 },{ 191,213 },{ 191,245 },{ 183,180 },{ 178,238 },{ 204,171 },{ 180,243 },{ 193,203 }, };
			OutputMess(Kerr, str7, 20);

			break;
		}
		case 3:
		{
			char str1[9][3] = { { 184,231 },{ 196,227 },{ 196,220 },{ 178,187 },{ 201,250 },{ 206,210 },{ 198,248 },{ 194,240 },{ 63,0 }, };
			OutputMess(Kerr, str1, 9);
			char str2[12][3] = { { 206,210 },{ 213,230 },{ 181,196 },{ 211,208 },{ 181,227 },{ 178,187 },{ 214,170 },{ 181,192 },{ 184,195 },{ 212,245 },{ 195,180 },{ 176,236 }, };
			OutputMess(Kerr, str2, 12); 
			char str3[10][3] = { { 206,210 },{ 210,187 },{ 182,168 },{ 200,195 },{ 196,227 },{ 202,167 },{ 205,251 },{ 193,203 },{ 46,46 },{ 46,0 }, };
			OutputMess(Kerr, str3, 10);
			char str4[15][3] = { { 178,187 },{ 187,225 },{ 44,214 },{ 187,211 },{ 208,206 },{ 210,215 },{ 212,188 },{ 186,187 },{ 225,200 },{ 195,206 },{ 210,215 },{ 212,188 },{ 186,202 },{ 167,205 },{ 251,0 }, };
			OutputMess(doubleZ, str4, 15); 
			char str5[4][3] = { { 196,227 },{ 215,246 },{ 181,196 },{ 182,212 }, };
			OutputMess(doubleZ, str5, 4); 
			char str6[2][3] = { { 213,230 },{ 181,196 }, };
			OutputMess(doubleZ, str6, 2);

			break;
		}
		case 4:
		{
			char str1[34][3] = { { 210,187 },{ 184,246 },{ 200,203 },{ 190,211 },{ 200,187 },{ 213,230 },{ 181,196 },{ 191,201 },{ 210,212 },{ 199,176 },{ 210,187 },{ 195,235 },{ 186,205 },{ 196,227 },{ 200,207 },{ 213,230 },{ 181,196 },{ 204,184 },{ 206,180 },{ 192,180 },{ 44,207 },{ 194,210 },{ 187,195 },{ 235,190 },{ 205,205 },{ 182,200 },{ 235,193 },{ 237,210 },{ 187,184 },{ 246,200 },{ 203,181 },{ 196,187 },{ 179,177 },{ 167,0 }, };
			OutputMess(Kerr, str1, 34);
			char str2[10][3] = { { 206,168 },{ 210,187 },{ 199,235 },{ 199,243 },{ 44,186 },{ 195,186 },{ 195,176 },{ 174,215 },{ 212,188 },{ 186,0 }, };
			OutputMess(doubleZ, str2, 10);
			char str3[8][3] = { { 210,213 },{ 204,218 },{ 187,225 },{ 186,195 },{ 186,195 },{ 176,174 },{ 215,212 },{ 188,186 }, };
			OutputMess(Kerr, str3, 8);
			char str4[7][3] = { { 210,213 },{ 204,218 },{ 196,220 },{ 205,252 },{ 181,244 },{ 203,251 },{ 181,196 }, };
			OutputMess(Kerr, str4, 7);
			break;
		}
		case 5:
		{
			char str1[18][3] = { { 196,199 },{ 184,246 },{ 213,194 },{ 179,253 },{ 193,203 },{ 206,210 },{ 214,174 },{ 205,226 },{ 214,187 },{ 184,248 },{ 185,253 },{ 210,187 },{ 184,246 },{ 187,185 },{ 202,199 },{ 193,189 },{ 184,246 },{ 200,203 }, };
			OutputMess(doubleZ, str1, 18);
			char str2[9][3] = { { 196,199 },{ 202,199 },{ 206,210 },{ 206,168 },{ 210,187 },{ 181,196 },{ 215,249 },{ 211,210 },{ 195,250 }, };
			OutputMess(doubleZ, str2, 9);
			char str3[10][3] = { { 206,210 },{ 211,214 },{ 210,187 },{ 180,206 },{ 177,187 },{ 189,245 },{ 192,240 },{ 184,189 },{ 204,229 },{ 193,203 }, };
			OutputMess(Kerr, str3, 10);
			char str4[9][3] = { { 213,226 },{ 184,246 },{ 198,189 },{ 176,178 },{ 210,185 },{ 204,171 },{ 208,210 },{ 184,163 },{ 193,203 }, };
			OutputMess(Kerr, str4, 9);

			break;
		}
		case 6:
		{
			char str1[4][3] = { { 208,194 },{ 196,234 },{ 191,236 },{ 192,214 }, };
			OutputMess(Kerr, str1, 4);
			char str2[10][3] = { { 208,161 },{ 210,213 },{ 204,218 },{ 208,194 },{ 181,196 },{ 210,187 },{ 196,234 },{ 210,170 },{ 191,170 },{ 208,196 }, };
			OutputMess(doubleZ, str2, 10);
			char str3[7][3] = { { 204,236 },{ 204,236 },{ 191,170 },{ 208,196 },{ 181,196 },{ 196,199 },{ 214,214 }, };
			OutputMess(doubleZ, str3, 7);
			char str4[5][3] = { { 215,246 },{ 196,227 },{ 207,235 },{ 215,246 },{ 181,196 }, };
			OutputMess(doubleZ, str4, 5); 
			break;
		}
		case 7:
		{
			char str1[12][3] = { { 202,216 },{ 193,227 },{ 181,227 },{ 202,216 },{ 181,196 },{ 203,175 },{ 215,197 },{ 44,176 },{ 235,210 },{ 185,190 },{ 170,208 },{ 209,0 }, };
			OutputMess(Kerr, str1, 12);
			char str2[10][3] = { { 196,227 },{ 195,199 },{ 182,188 },{ 212,218 },{ 206,210 },{ 190,205 },{ 186,220 },{ 191,170 },{ 208,196 },{ 193,203 }, };
			OutputMess(doubleZ, str2, 10);
			char str3[3][3] = { { 210,187 },{ 214,177 },{ 212,218 }, };
			OutputMess(Kerr, str3, 3);
			break;
		}
		case 8:
		{
			char str1[9][3] = { { 196,199 },{ 203,253 },{ 214,170 },{ 181,192 },{ 196,227 },{ 212,218 },{ 181,200 },{ 194,240 },{ 63,0 }, };
			OutputMess(Kerr, str1, 9);
			char str2[6][3] = { { 206,210 },{ 178,187 },{ 181,189 },{ 196,172 },{ 198,245 },{ 176,201 }, };
			OutputMess(doubleZ, str2, 6);
			char str3[11][3] = { { 196,199 },{ 196,227 },{ 178,187 },{ 197,194 },{ 187,198 },{ 187,168 },{ 178,203 },{ 193,185 },{ 193,203 },{ 194,239 },{ 63,0 }, };
			OutputMess(Kerr, str3, 11);
			char str4[8][3] = { { 206,210 },{ 197,194 },{ 201,182 },{ 186,195 },{ 183,185 },{ 178,187 },{ 197,194 },{ 205,237 }, };
			OutputMess(doubleZ, str4, 8);
			char str5[14][3] = { { 208,208 },{ 176,201 },{ 33,0 },{ 196,199 },{ 189,241 },{ 196,234 },{ 199,233 },{ 200,203 },{ 189,218 },{ 190,205 },{ 181,165 },{ 215,197 },{ 176,201 },{ 33,0 }, };
			OutputMess(Kerr, str5, 14);
			char str6[6][3] = { { 187,165 },{ 200,176 },{ 182,212 },{ 183,189 },{ 203,192 },{ 181,200 }, };
			OutputMess(Kerr, str6, 6);
			char str7[6][3] = { { 196,227 },{ 178,187 },{ 197,194 },{ 206,210 },{ 182,239 },{ 196,227 }, };
			OutputMess(doubleZ, str7, 6);
			char str8[2][3] = { { 178,187 },{ 197,194 }, };
			OutputMess(Kerr, str8, 2);

			break;
		}
		default:
			break;
		}

		Sleep(stoptimelonglong);

	}

	
	system("cls");
	setColor(5);
	char str1[MaxSize][3] = { { 207,224 },{ 203,198 },{ 181,196 },{ 193,233 },{ 187,234 }, };
	printf("%s", "        ");
	for (int i = 0; i < 5; ++i)
	{
		Sleep(stoptimelong);
		printf("%s", str1[i]);
		Sleep(stoptimeshort);
	}
	printf("\n");

	Sleep(stoptimelonglong);
}

/*================= floatHeart ======================*/
#define RATE 33

float f(float x, float y, float z) {
	float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
	return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
}

float h(float x, float z) {
	for (float y = 1.0f; y >= 0.0f; y -= 0.001f)
		if (f(x, y, z) <= 0.0f)
			return y;
	return 0.0f;
}

void Third_floatHeart(void)
{
	setColor(12);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	_TCHAR buffer[25][80] = { _T(' ') };
	_TCHAR ramp[] = _T(".:-=+*#%@");

	for (float t = 0.0f; t<50.0f; t += 0.1f)
	{
		int sy = 0;
		float s = sinf(t);
		float a = s * s * s * s * 0.2f;

		for (float z = 1.3f; z > -1.2f; z -= 0.1f)
		{
			_TCHAR* p = &buffer[sy++][0];
			float tz = z * (1.2f - a);

			for (float x = -1.5f; x < 1.5f; x += 0.05f)
			{
				float tx = x * (1.2f + a);
				float v = f(tx, 0.0f, tz);

				if (v <= 0.0f)
				{
					float y0 = h(tx, tz);
					float ny = 0.01f;
					float nx = h(tx + ny, tz) - y0;
					float nz = h(tx, tz + ny) - y0;
					float nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
					float d = (nx + ny - nz) * nd * 0.5f + 0.5f;
					*p++ = ramp[(int)(d * 5.0f)];
				}
				else
					*p++ = ' ';
			}
		}

		for (sy = 0; sy < 25; sy++)
		{
			COORD coord = { 0, sy };
			SetConsoleCursorPosition(handle, coord);
			WriteConsole(handle, buffer[sy], 61, NULL, 0);
		}

		Sleep(RATE);
	}
}


int main(void)
{
	system("title Happy Birthday zyT");

	First_HelloWorld();
	Second_article();
	Third_floatHeart();


	system("pause");
	return 0;
}
