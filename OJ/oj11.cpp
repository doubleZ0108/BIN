/*
Q: "数的计数
	先输入一个自然数 n~(n\le 1000)n (n≤1000)，然后对此自然数按照如下方法进行处理：
1. 不作任何处理；
2. 在它的左边加上一个自然数，但该自然数不能超过原数的一半；
3. 加上数后，继续按此规则进行处理,直到不能再加自然数为止。"
注：主需要计数，不需要输出

样例：输入6
（1）6
（2）16
（3）26
（4）126
（5）36
（6）136
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	queue<int> que;
	que.push(n);

	int top, cnt = 0;
	while (!que.empty())
	{
		top = que.front();	que.pop();
		cnt++;

		for (int i = 1; i <= top / 2; ++i)
		{
			que.push(i);
		}
	}

	cout << cnt << endl;

	system("pause");
	return 0;
}