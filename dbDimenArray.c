/*
C���Զ�̬���ٶ�ά����
*/

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int row = 3, col = 4;

	/*����һ: ��һά����ģ���ά����*/
	//��i�е�j��Ϊ arr[i*col+j]
	int *arr = malloc(row*col * sizeof(int));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			arr[i*col + j] = 0;
		}
	}

	free(arr);		//�������ͷ�


	/*������: �ö���ָ����ʶ�̬���ٵĶ�ά����*/
	//��i�е�j�о��� Arr[i][j]

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

	//����ͷ��ڴ��е㸴��
	for (int i = 0; i < row; ++i)
	{
		free(Arr[i]);
	}
	free(Arr);


	system("pause");
	return 0;
}