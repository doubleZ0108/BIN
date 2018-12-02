/*
Q: "���������� ���Լ�� �� ��С������"
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

	printf("���Լ����: %lld\n", n);
	printf("�ݹ������Լ����: %lld\n", GCD(savem, saven));
	printf("��С��������: %lld\n", savem*saven / n);

	system("pause");
	return 0;
}