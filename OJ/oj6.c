/*
Q: "小明有五本新书，要借给A，B，C三位小朋友，若每人每次只能借一本，则可以有多少种不同的借法？"
穷举法
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
					//也可以写 if(a!=b && a!=c && b!=c) 但是没这个优美
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