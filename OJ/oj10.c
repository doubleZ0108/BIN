/*
Q: "编写一个递归算法，找出从自然数1,2,3,4,…,n中任取r个数的所有组合。"
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Combination(int n, int m)
{
	if (m == 0 || m == n) { return 1; }
	else { return (Combination(n - 1, m) + Combination(n - 1, m - 1)); }
}
int main(void)
{
	int n, m;
	printf("请输入C(n,m)中的n和m：");
	scanf("%d %d", &n, &m);

	printf("C(%d, %d) = %d\n", n, m, Combination(n, m));

	system("pause");
	return 0;
}