#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

#define ROW 10

int main(void)
{
	int leftup=0, up;
	queue<int> Q;
	Q.push(1); Q.push(1);

	for (int i = 1; i <= ROW; ++i)
	{
		Q.push(0);
		for (int j = 0; j < i + 2; ++j)
		{
			up = Q.front();	Q.pop();
			Q.push(up + leftup);
			leftup = up;

			if (j != i + 1)
			{
				cout << up << ' ';
			}
		}
		cout << endl;
	}

	system("pause");
	return 0;
}