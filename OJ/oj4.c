/*
Q: "求两个数的 最大公约数 和 最小公倍数"
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long GCD(long m, long n)
{
	if (m%n == 0) { return n; }
	else
	{
		GCD(n, m%n);
	}
}
int main(void)
{
	long long m, n;
	scanf("%lld %lld", &m, &n);

	long long buf;
	long long savem = m, saven = n;

	while (buf = m % n)
	{
		m = n;
		n = buf;
	}

	printf("最大公约数是: %lld\n", n);
	printf("递归解得最大公约数是: %lld\n", GCD(savem, saven));
	printf("最小公倍数是: %lld\n", savem*saven / n);

	system("pause");
	return 0;
}