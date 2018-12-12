/*
Q: "百钱买白鸡: 鸡翁一，值钱五，鸡母一，值钱三，鸡雏三，值钱一，百钱买百鸡，问翁、母、雏各几何？"
tips: 其中鸡雏只能三个三个买
穷举法
*/
#define _CRTSECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Normal()
{
	int x, y, z;
	for (x = 0; x <= 20; ++x)
	{
		for (y = 0; y <= 33; ++y)
		{
			for (z = 0; z <= 300; ++z)
			{
				if (z % 3 == 0 && x + y + z == 100 && 5 * x + 3 * y + z / 3 == 100)
				{
					printf("鸡翁%d，鸡母%d，鸡雏%d\n", x, y, z);
				}
			}
		}
	}
}
void Improve1()
{
	int x, y, z;
	for (x = 0; x <= 20; ++x)
	{
		for (y = 0; y <= 33; ++y)
		{
			for (z = 0; z <= 300; z+=3)
			{
				if (x + y + z == 100 && 5 * x + 3 * y + z / 3 == 100)
				{
					printf("鸡翁%d，鸡母%d，鸡雏%d\n", x, y, z);
				}
			}
		}
	}
}
void Improve2()
{
	int x, y, z;
	for (x = 0; x <= 20; ++x)
	{
		for (y = 0; y <= 33; ++y)
		{
			z = 100 - x - y;		//已经明确总数了, 可以减少一层循环了

			if (z % 3 == 0 && 5 * x + 3 * y + z / 3 == 100)
				//此时就还要判断z是否是3的倍数
			{
				printf("鸡翁%d，鸡母%d，鸡雏%d\n", x, y, z);
			}
		}
	}
}

int main(void)
{
	printf("normal: \n");
	Normal();

	printf("improve1: \n");
	Improve1();

	printf("improve2: \n");
	Improve2();

	system("pause");
	return 0;
}