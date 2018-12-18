/*
Q: "һ����СΪn�ķ���ͼ��ͼ��'.'��'#'�����ֹ��ɣ�
'.'��ʾ��λ��ʲô��û�У�
'#'��ʾ�ܿ���ϸ����һ���֣������������(4������)������'#'��ͬ����һ����ϸ����
ͼ��һ���ж��ٸ�ϸ���أ��� "

�������룺
		4
		#.#.
		###.
		....
		#..#
���������3

�㷨��ƣ�DFS����
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void DFS(vector<vector<char> > &map, vector<vector<bool> > &visited, 
	int n, int row, int col)
{
	if (row < 0 || row >= n || col < 0 || col >= n ||		//��һ�������жϳ���ͼ�߽�
		visited[row][col] || map[row][col] == '.')			//�ڶ����ж� ������ʹ��ͷ��� 
															//������û�ж���Ҳ����
	{ return; }

	visited[row][col] = true;				//�������Ϊ���ʹ���

	/*���������ĸ���������� ���ж����Ķ���Ϊ���ʹ���*/
	DFS(map, visited, n, row - 1, col);
	DFS(map, visited, n, row, col - 1);
	DFS(map, visited, n, row + 1, col);
	DFS(map, visited, n, row, col + 1);

}

int main(void)
{
	int n;
	cin >> n;

	vector<vector<char> > map(n, vector<char>(n, 0));
	vector<vector<bool> > visited(n, vector<bool>(n, 0));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
		}
	}
	
	int count = 0;
	/*
	DFS�ĺ���˼����
	û����һ�����ж���, �Ͱ���λ��visited��Ϊtrue
	֮���ٵݹ�İ��������ͨ�����е�visited��Ϊtrue, �����´�ѭ���������Ͳ����������
	*/
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!visited[i][j] && map[i][j] == '#')
			{
				DFS(map, visited, n, i, j);		//�����Ѱ�����������������е�visited��Ϊtrue
				++count;
			}
		}
	}

	cout << count << endl;

	system("pause");
	return 0;
}