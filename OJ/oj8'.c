/*
Q: "һ����СΪn�ķ���ͼ��ͼ��'.'��'#'�����ֹ��ɣ�
'.'��ʾ��λ��ʲô��û�У�
'#'��ʾ�ܿ���ϸ����һ���֣������������(4������)������'#'��ͬ����һ����ϸ����
ͼ��һ���ж��ٸ�ϸ���أ��� "
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void DFS(char **map, int **visited, int n, int row, int col)
{
	if (row < 0 || row >= n || col < 0 || col >= n) { return; }

	visited[row][col] = 1;


	if (row - 1 > -1)
	{
		if (!visited[row - 1][col] && map[row - 1][col] == '#')
		{
			DFS(map, visited, n, row - 1, col);
		}
	}
	if (col - 1 > -1)
	{
		if (!visited[row][col - 1] && map[row][col - 1] == '#')
		{
			DFS(map, visited, n, row, col - 1);
		}
	}
	if (row + 1 < n)
	{
		if (!visited[row + 1][col] && map[row + 1][col] == '#')
		{
			DFS(map, visited, n, row + 1, col);
		}
	}
	if (col + 1 < n)
	{
		if (!visited[row][col + 1] && map[row][col + 1] == '#')
		{
			DFS(map, visited, n, row, col + 1);
		}
	}
	
}
int main(void)
{
	int n;
	scanf("%d", &n);
	getchar();

	char ** map;
	map = (char**)malloc(n * sizeof(char*));

	for (int i = 0; i < n; i++) 
	{
		map[i] = (char*)malloc(n * sizeof(char));
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			map[i][j] = '\0';
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%c", &map[i][j]);
		}
		getchar();
	}
	

	int ** visited;
	visited = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n ; i++)
	{
		visited[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n ; ++i)
	{
		for (int j = 0; j < n ; ++j)
		{
			visited[i][j] = 0;
		}
	}
	

	int cnt = 0;
	for (int i = 0; i < n ; ++i)
	{
		for (int j = 0; j < n ; ++j)
		{
			if (!visited[i][j] && map[i][j] == '#')
			{
				DFS(map, visited, n, i, j);
				++cnt;
			}
		}
	}

	printf("%d", cnt);


	for (int i = 0; i < n ; i++)
	{
		free(map[i]);
	}
	free(map);
	for (int i = 0; i < n; i++)
	{
		free(visited[i]);
	}
	free(visited);

	system("pause");
	return 0;
}