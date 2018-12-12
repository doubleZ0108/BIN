/*
Q: "��Ǯ��׼�: ����һ��ֵǮ�壬��ĸһ��ֵǮ������������ֵǮһ����Ǯ��ټ������̡�ĸ���������Σ�"
tips: ���м���ֻ������������
��ٷ�
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
					//printf("����%d����ĸ%d������%d\n", x, y, z);
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
					//printf("����%d����ĸ%d������%d\n", x, y, z);
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
			z = 100 - x - y;		//�Ѿ���ȷ������, ���Լ���һ��ѭ����

			if (z % 3 == 0 && 5 * x + 3 * y + z / 3 == 100)
				//��ʱ�ͻ�Ҫ�ж�z�Ƿ���3�ı���
			{
				//printf("����%d����ĸ%d������%d\n", x, y, z);
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