/*
Q: "百钱买白鸡: 鸡翁一，值钱五，鸡母一，值钱三，鸡雏三，值钱一，百钱买百鸡，问翁、母、雏各几何？"
tips: 其中鸡雏只能三个三个买
穷举法
*/
#define _CRTSECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxSize 10000

void Normal()
{
	int x, y, z;
	int cnt = 0;
	for (x = 0; x <= 20; ++x)
	{
		for (y = 0; y <= 33; ++y)
		{
			for (z = 0; z <= 300; ++z)
			{
				if (z % 3 == 0 && x + y + z == 100 && 5 * x + 3 * y + z / 3 == 100)
				{
					//printf("鸡翁%d，鸡母%d，鸡雏%d\n", x, y, z);
					++cnt;
				}
			}
		}
	}
}
void Improve1()
{
	int x, y, z;
	int cnt = 0;
	for (x = 0; x <= 20; ++x)
	{
		for (y = 0; y <= 33; ++y)
		{
			for (z = 0; z <= 300; z+=3)
			{
				if (x + y + z == 100 && 5 * x + 3 * y + z / 3 == 100)
				{
					//printf("鸡翁%d，鸡母%d，鸡雏%d\n", x, y, z);
					++cnt;
				}
			}
		}
	}
}
void Improve2()
{
	int x, y, z;
	int cnt = 0;
	for (x = 0; x <= 20; ++x)
	{
		for (y = 0; y <= 33; ++y)
		{
			z = 100 - x - y;		//已经明确总数了, 可以减少一层循环了

			if (z % 3 == 0 && 5 * x + 3 * y + z / 3 == 100)
				//此时就还要判断z是否是3的倍数
			{
				//printf("鸡翁%d，鸡母%d，鸡雏%d\n", x, y, z);
				++cnt;
			}
		}
	}
}

int main(void)
{
	clock_t start, end;
	double duration;

	start = clock();
	for (int i = 0; i < MaxSize; ++i)
	{
		//printf("normal: \n");
		Normal();
	}
	end = clock();
	duration = (double)(end - start) / CLK_TCK;
	printf("normal: %f\n", duration);


	start = clock();
	for (int i = 0; i < MaxSize; ++i)
	{
		//printf("improve1: \n");
		Improve1();
	}
	end = clock();
	duration = (double)(end - start) / CLK_TCK;
	printf("improve1: %f\n", duration);


	start = clock();
	for (int i = 0; i < MaxSize; ++i)
	{
		//printf("improve2: \n");
		Improve2();
	}
	end = clock();
	duration = (double)(end - start) / CLK_TCK;
	printf("improve2: %f\n", duration);


	system("pause");
	return 0;
}