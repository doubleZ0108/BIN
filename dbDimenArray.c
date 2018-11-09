/*
C语言动态开辟二维数组
*/

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int row = 3, col = 4;

	/*方法一: 用一维数组模拟二维数组*/
	//第i行第j列为 arr[i*col+j]
	int *arr = malloc(row*col * sizeof(int));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			arr[i*col + j] = 0;
		}
	}

	free(arr);		//最后别忘释放


	/*方法二: 用二级指针访问动态开辟的二维数组*/
	//第i行第j列就是 Arr[i][j]

	int **Arr = malloc(row * sizeof(int*));
	for(int i=0;i<row;++i)
	{
		Arr[i] = malloc(col * sizeof(int));
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			Arr[i][j] = 0;
		}
	}

	//这个释放内存有点复杂
	for (int i = 0; i < row; ++i)
	{
		free(Arr[i]);
	}
	free(Arr);


	system("pause");
	return 0;
}