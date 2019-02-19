#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include<time.h>
#include <tchar.h>

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
/*================= article ======================*/
#define MaxSize 5
#define stoptimeshort  200
#define stoptimelong   500

void Second_article(void)
{
	//相似的灵魂
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

	//小巧玲珑迷你可爱的160cm小萝莉
	char strhelloworld[13][6] = { { 208,161 },{ 199,201 },{ 193,225 },{ 231,231 },{ 195,212 },{ 196,227 },{ 191,201 },{ 176,174 },{ 181,196 },"160cm",{ 208,161 },{ 194,220 },{ 192,242 }, };
	printf("%s", "        ");
	for (int i = 0; i < 13; ++i)
	{
		Sleep(stoptimelong);
		printf("%s", strhelloworld[i]);
		Sleep(stoptimeshort);
	}
	printf("\n");
	
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

	Second_article();
	//Third_floatHeart();

	system("pause");
	return 0;
}
