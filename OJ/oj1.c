/*
Q: "升序序列,输出第一个大于或等于key值的位置"
Input: n为序列长度 m为查询次数
		第二行为n个数 (升序)
Output: 第一个大于或等于key的位置

举例:
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
			//flag是这道题的核心, 最后一次的查找状态表示到底应该输出那个位置

		int low = 0, high = n - 1, mid;
		parr = arr;
		while (low <= high)
			//正常跑折半查找
		{
			mid = (low + high) / 2;
			if (*(parr + mid) < key)
				//最后一次找的是后半段
				//因此此时第一个大于key的位置应该是mid+1
			{
				low = mid + 1;
				flag = -1;
			}
			else if (*(parr + mid) > key)
				//最后一次找的是前半段, high往前缩到mid前的位置
				//所以mid就会最终的结果
			{
				high = mid - 1;
				flag = -2;
			}
			else
				//如果找到了这个数, 直接输出mid就行了
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