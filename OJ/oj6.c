/*
Q: "С�����屾���飬Ҫ���A��B��C��λС���ѣ���ÿ��ÿ��ֻ�ܽ�һ����������ж����ֲ�ͬ�Ľ跨��"
��ٷ�
*/
#define _CRTSECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int cnt = 1;

	for (int a = 1; a <= 5; ++a)
	{
		for (int b = 1; b <= 5; ++b)
		{
			for (int c = 1; c <= 5; ++c)
			{
				if ((a - b)*(a - c)*(b - c) != 0)
					//Ҳ����д if(a!=b && a!=c && b!=c) ����û�������
				{
					printf("%2d: %d,%d,%d\n", cnt, a, b, c);
					cnt++;

				}
			}
		}
	}


	system("pause");
	return 0;
}