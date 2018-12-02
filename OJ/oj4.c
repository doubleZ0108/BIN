/*
Q: "���������� ���Լ�� �� ��С������"
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int GCD_division(int m, int n)
//շת�����
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
//�ݹ鷨
{
	if (m%n == 0) { return n; }
	else
	{
		GCD_recrusion(n, m%n);
	}
}
int GCD_subtraction(int m, int n)
//շת�����
{
	while (m != n)
	{
		//max(m, n) = max(m, n) - min(m, n);			//Q: �ʺű��ʽΪʲô������Ϊ��ֵ
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

	printf("շת�����������Լ����: %d\n", GCD_division(m,n));
	printf("�ݹ������Լ����: %d\n", GCD_recrusion(m, n));
	printf("շת�����������Լ����: %d\n", GCD_subtraction(m,n));

	printf("��С��������: %d\n", m*n / GCD_division(m, n));

	system("pause");
	return 0;
}