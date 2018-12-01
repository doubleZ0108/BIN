/*
Q: "字典序排列"
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
//将指定的起始和终点之间的数逆序
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
//注: 如果当前已经是最后一个序列了(987654321), 则会不停的循环等待
{
	int i, j, k;
	
	/*1. 找到最后一个 arr[i-1]比arr[i]小 的位置*/
	for (i = size - 1; i >= 0; --i)
	{
		if (arr[i] > arr[i - 1]) { break; }
	}

	/*2. 找到最后一个 arr[j] 比 这个i之前的一位(i-1)大 的位置*/
	for (j = size - 1; j > i - 1; --j)
	{
		if (arr[j] > arr[i - 1]) { break; }
	}

	/*3. 交换arr[i-1] 和 arr[j]*/
	swap(&arr[i - 1], &arr[j]);

	/*4. 将换后的 i-1之后的元素逆序*/
	reverse(&arr[i], &arr[size - 1]);
}

int main(void)
{
	int index;
	printf("你想进行几个数的全排列: ");
	scanf("%d", &index);

	int *arr = malloc(index * sizeof(int));

	for (int cnt=1, *parr=arr; parr < arr + index; ++parr,++cnt)
		//设置初始的序列 (123456789)
	{
		*parr = cnt;
	}

	for (int i = 0; i < Fact(index)-1; ++i)
		//这里用阶乘-1作为循环终止条件是因为
		//最后一次只showArray, find不到next了, 函数会一直等待
	{
		showArray(arr, index);
		findNext(arr, index);
	}
	showArray(arr, index);

	free(arr);
	system("pause");
	return 0;
}