/*
Q: "描述
一共有n个人（以1--n编号）向佳佳要照片，而佳佳只能把照片给其中的k个人。
佳佳按照与他们的关系好坏的程度给每个人赋予了一个初始权值W[i]。
然后将初始权值从大到小进行排序，每人就有了一个序号D[i]（取值同样是1--n）。
按照这个序号对10取模的值将这些人分为10类。
也就是说定义每个人的类别序号C[i]的值为(D[i]-1) mod 10 +1，显然类别序号的取值为1--10。
第i类的人将会额外得到E[i]的权值。
你需要做的就是求出加上额外权值以后，最终的权值最大的k个人，并输出他们的编号。
在排序中，如果两人的W[i]相同，编号小的优先。

格式
输入格式
第一行输出用空格隔开的两个整数，分别是n和k。

第二行给出了10个正整数，分别是E[1]到E[10]。

第三行给出了n个正整数，第i个数表示编号为i的人的权值W[i]。

输出格式
只需输出一行用空格隔开的k个整数，分别表示最终的W[i]从高到低的人的编号。"
*/
//多关键码的排序算法

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define INFINITE 1<<30

struct NODE
{
	int W, D, C;
	int name;
};

void QuickSort(vector<NODE> &people, int low, int high)
{
	if (low >= high) { return; }

	int savei = low, savej = high;
	NODE key = people[low];

	//排序的依据是 
	//权值大的优先
	//如果权值相同 编号小的优先
	while (low < high)
	{
		while (low<high && (people[high].W<key.W ||
			(people[high].W == key.W && people[high].name>key.name)))
		{
			--high;
		}
		if (people[high].W>key.W || (people[high].W == key.W && people[high].name<key.name))
		{
			people[low] = people[high];
			++low;
		}
		while (low < high && (people[low].W > key.W ||
			(people[low].W == key.W && people[low].name<key.name)))
		{
			++low;
		}
		if (people[low].W<key.W || (people[low].W == key.W && people[low].name>key.name))
		{
			people[high] = people[low];
			--high;
		}
	}

	people[low] = key;

	QuickSort(people, savei, low - 1);
	QuickSort(people, low + 1, savej);
}

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> E(11, 0);
	for (int i = 1; i <= 10; ++i) { cin >> E[i]; }

	vector<NODE> people(n + 1);
	people[0].W = INFINITE;

	for (int i = 1; i <= n; ++i)
	{
		people[i].name = i;
		cin >> people[i].W;
	}

	QuickSort(people, 0, n);

	for (int i = 1; i <= n; ++i)
	{
		people[i].D = i;
		people[i].C = (people[i].D - 1) % 10 + 1;
	}

	for (int i = 1; i <= n; ++i)
	{
		people[i].W += E[people[i].C];
	}
	QuickSort(people, 0, n);

	for (int i = 1; i <= k; ++i)
	{
		cout << people[i].name << ' ';
	}

	system("pause");
	return 0;
}