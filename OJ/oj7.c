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

}
void Improve2()
{

}
int main(void)
{
	Normal();


	system("pause");
	return 0;
}