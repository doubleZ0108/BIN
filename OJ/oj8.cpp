/*
Q: "一个大小为n的方形图像，图由'.'，'#'两部分构成，
'.'表示该位置什么有没有，
'#'表示能看到细胞的一部分，多个上下左右(4个方向)相连的'#'共同构成一个大细胞。
图中一共有多少个细胞呢？。 "

样例输入：
		4
		#.#.
		###.
		....
		#..#
样例输出：3

算法设计：DFS深搜
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
	if (row < 0 || row >= n || col < 0 || col >= n ||		//第一行用来判断出地图边界
		visited[row][col] || map[row][col] == '.')			//第二行判断 如果访问过就返回 
															//如果这点没有东西也返回
	{ return; }

	visited[row][col] = true;				//把这点置为访问过了

	/*上下左右四个方向调深搜 把有东西的都置为访问过了*/
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
	DFS的核心思想是
	没看到一个点有东西, 就把这位的visited置为true
	之后再递归的把与这点连通的所有点visited置为true, 这样下次循环到这个点就不会掉深搜了
	*/
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!visited[i][j] && map[i][j] == '#')
			{
				DFS(map, visited, n, i, j);		//调深搜把与这个点相连的所有点visited置为true
				++count;
			}
		}
	}

	cout << count << endl;

	system("pause");
	return 0;
}