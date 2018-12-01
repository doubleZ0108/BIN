/*
Q: "��������,�����һ�����ڻ����keyֵ��λ��"
Input: nΪ���г��� mΪ��ѯ����
		�ڶ���Ϊn���� (����)
Output: ��һ�����ڻ����key��λ��

����:
I:
4 2
1 5 8 10
3
9

O:
1
3
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	int *arr = malloc(n * sizeof(int));
	int *parr = arr;
	for (parr = arr; parr < arr + n; ++parr)
	{
		scanf("%d", parr);
	}

	for (int i = 0; i < m; ++i)
	{
		int key;
		scanf("%d", &key);

		int flag = 0;
			//flag�������ĺ���, ���һ�εĲ���״̬��ʾ����Ӧ������Ǹ�λ��

		int low = 0, high = n - 1, mid;
		parr = arr;
		while (low <= high)
			//�������۰����
		{
			mid = (low + high) / 2;
			if (*(parr + mid) < key)
				//���һ���ҵ��Ǻ���
				//��˴�ʱ��һ������key��λ��Ӧ����mid+1
			{
				low = mid + 1;
				flag = -1;
			}
			else if (*(parr + mid) > key)
				//���һ���ҵ���ǰ���, high��ǰ����midǰ��λ��
				//����mid�ͻ����յĽ��
			{
				high = mid - 1;
				flag = -2;
			}
			else
				//����ҵ��������, ֱ�����mid������
			{
				printf("%d\n", mid);
				flag = 1;
				break;
			}
		}
		if (flag!=1)
		{
			printf("%d\n", flag == -1 ? mid+1: mid);
		}
	}

	free(arr);
	system("pause");
	return 0;
}