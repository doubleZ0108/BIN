/*
Q: "��дһ���ݹ��㷨���ҳ�����Ȼ��1,2,3,4,��,n����ȡr������������ϡ�"
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
	printf("������C(n,m)�е�n��m��");
	scanf("%d %d", &n, &m);

	printf("C(%d, %d) = %d\n", n, m, Combination(n, m));

	system("pause");
	return 0;
}