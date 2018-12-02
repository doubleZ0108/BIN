/*
Q: "求两个数的 最大公约数 和 最小公倍数"
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int GCD_division(int m, int n)
//辗转相除法
{
	int buf;
	while (buf = m % n)
	{
		m = n;
		n = buf;
	}
	return n;
}
int GCD_recrusion(int m, int n)
//递归法
{
	if (m%n == 0) { return n; }
	else
	{
		GCD_recrusion(n, m%n);
	}
}
int GCD_subtraction(int m, int n)
//辗转相减法
{
	while (m != n)
	{
		//max(m, n) = max(m, n) - min(m, n);			//Q: 问号表达式为什么不能作为左值
		if (m > n)
		{
			m = m - n;
		}
		else
		{
			n = n - m;
		}
	}
	return m;
}

int main(void)
{
	int m, n;
	scanf("%d %d", &m, &n);

	printf("辗转相除法解得最大公约数是: %d\n", GCD_division(m,n));
	printf("递归解得最大公约数是: %d\n", GCD_recrusion(m, n));
	printf("辗转相减法解得最大公约数是: %d\n", GCD_subtraction(m,n));

	printf("最小公倍数是: %d\n", m*n / GCD_division(m, n));

	system("pause");
	return 0;
}