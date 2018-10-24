/*
队列实现打印杨辉三角形
*/
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
#define ROW 20
int main(void)
{
	queue<int> que;
	que.push(1); que.push(1);

	int leftup = 0, up;
	for (int i = 1; i <= ROW; ++i)
	{
		que.push(0);
		for (int j = 0; j < i + 2; ++j)
		{
			up = que.front();
			que.pop();
			que.push(leftup + up);
			leftup = up;
			if (j != i+1)
			{
				cout << up << ' ';
			}
		}
		cout << endl;
	}

	system("pause");
	return 0;
}