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
			//第i行有i+1个元素, 但是我们要通过i+2个值才能得到这i+1个值
			//在每一行最后加了一个0
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