/*
给定公司N名员工的工龄，要求按工龄增序输出每个工龄段有多少员工。

输入格式:
输入首先给出正整数N即员工总人数；随后给出N个整数，即每个员工的工龄

输出格式:
按工龄的递增顺序输出每个工龄的员工个数，格式为：“工龄:人数”。每项占一行。如果人数为0则不输出该项。

输入样例:
8
10 2 0 5 7 2 5 2
输出样例:
0:1
2:3
5:2
7:1
10:1

*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;

typedef int age;

int main(void)
{
	int n;  cin >> n;
	map<age, int> worker;

	int bufage;
	for (int i = 0; i<n; ++i)
	{
		cin >> bufage;
		if (worker.count(bufage))
		{
			worker[bufage]++;
		}
		else
		{
			worker[bufage] = 1;
		}
	}

	for (auto iter = worker.begin(); iter != worker.end(); ++iter)
	{
		cout << iter->first << ":" << iter->second << endl;
	}

	system("pause");
	return 0;
}
