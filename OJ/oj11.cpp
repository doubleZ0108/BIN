/*
Q: "���ļ���
	������һ����Ȼ�� n~(n\le 1000)n (n��1000)��Ȼ��Դ���Ȼ���������·������д���
1. �����κδ���
2. ��������߼���һ����Ȼ����������Ȼ�����ܳ���ԭ����һ�룻
3. �������󣬼������˹�����д���,ֱ�������ټ���Ȼ��Ϊֹ��"
ע������Ҫ����������Ҫ���

����������6
��1��6
��2��16
��3��26
��4��126
��5��36
��6��136
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