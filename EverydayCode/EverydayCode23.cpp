#include <iostream>
#include <cstdlib>
#include <queue>

#define MaxSize 10
using namespace std;
int main(void)
{
	queue<int> que;
	que.push(1); que.push(1);

	int up, upleft = 0;

	for (int i = 1; i <= MaxSize; ++i)
	{
		que.push(0);

		for (int j = 0; j <= i + 1; ++j)
			//��i����i+1��Ԫ��, ��������Ҫͨ��i+2��ֵ���ܵõ���i+1��ֵ
			//��ÿһ��������һ��0
		{
			up = que.front();
			que.pop();

			que.push(up + upleft);

			if (j != i+1)
			{
				cout << up << ' ';
			}
			upleft = up;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}