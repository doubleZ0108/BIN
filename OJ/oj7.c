/*
Q: "��Ǯ��׼�: ����һ��ֵǮ�壬��ĸһ��ֵǮ������������ֵǮһ����Ǯ��ټ������̡�ĸ���������Σ�"
tips: ���м���ֻ������������
��ٷ�
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
					printf("����%d����ĸ%d������%d\n", x, y, z);
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
					printf("����%d����ĸ%d������%d\n", x, y, z);
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
			z = 100 - x - y;		//�Ѿ���ȷ������, ���Լ���һ��ѭ����

			if (z % 3 == 0 && 5 * x + 3 * y + z / 3 == 100)
				//��ʱ�ͻ�Ҫ�ж�z�Ƿ���3�ı���
			{
				printf("����%d����ĸ%d������%d\n", x, y, z);
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