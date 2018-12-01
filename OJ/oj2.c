/*
Q: "�ֵ�������"
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Fact(int n)
{
	int fact = 1;
	for (; n > 1; --n)
	{
		fact *= n;
	}
	return fact;
}
void swap(int *a, int *b)
{
	int buf = *a;
	*a = *b;
	*b = buf;
}
void reverse(int *start, int *end)
//��ָ������ʼ���յ�֮���������
{
	int buf;
	for (int *ps = start, *pe = end; ps <= pe; ++ps, --pe)
	{
		buf = *ps;
		*ps = *pe;
		*pe = buf;
	}
}
void showArray(int arr[], int size)
{
	for (int *parr = arr; parr < arr + size; ++parr)
	{
		printf("%d ", *parr);
	}
	printf("\n");
}

void findNext(int arr[], int size)
//ע: �����ǰ�Ѿ������һ��������(987654321), ��᲻ͣ��ѭ���ȴ�
{
	int i, j, k;
	
	/*1. �ҵ����һ�� arr[i-1]��arr[i]С ��λ��*/
	for (i = size - 1; i >= 0; --i)
	{
		if (arr[i] > arr[i - 1]) { break; }
	}

	/*2. �ҵ����һ�� arr[j] �� ���i֮ǰ��һλ(i-1)�� ��λ��*/
	for (j = size - 1; j > i - 1; --j)
	{
		if (arr[j] > arr[i - 1]) { break; }
	}

	/*3. ����arr[i-1] �� arr[j]*/
	swap(&arr[i - 1], &arr[j]);

	/*4. ������� i-1֮���Ԫ������*/
	reverse(&arr[i], &arr[size - 1]);
}
void Permutation_4process(int arr[], int size)
{
	for (int i = 0; i < Fact(size) - 1; ++i)
		//�����ý׳�-1��Ϊѭ����ֹ��������Ϊ
		//���һ��ֻshowArray, find����next��, ������һֱ�ȴ�
	{
		showArray(arr, size);
		findNext(arr, size);
	}
	showArray(arr, size);
}


void Recrusion(int begin, int end, int arr[], int size)
{
	if (begin == end)
	{
		showArray(arr, size);
	}
	else
	{
		for (int i = begin; i <= end; ++i)
		{
			swap(&arr[i], &arr[begin]);
			Recrusion(begin + 1, end, arr, size);
			swap(&arr[i], &arr[begin]);
		}
	}
}
void Permutation_recrusion(int arr[], int size)
{
	Recrusion(0, size - 1, arr, size);
}


int main(void)
{
	int size;
	printf("������м�������ȫ����: ");
	scanf("%d", &size);

	int *arr = malloc(size * sizeof(int));

	for (int cnt=1, *parr=arr; parr < arr + size; ++parr,++cnt)
		//���ó�ʼ������ (123456789)
	{
		*parr = cnt;
	}

	/*ȫ���������㷨һ: �����е�4����(�ֵ���)*/
	Permutation_4process(arr, size);

	/*ȫ���������㷨��: �ݹ�(���ֵ���)*/
	Permutation_recrusion(arr, size);


	free(arr);
	system("pause");
	return 0;
}