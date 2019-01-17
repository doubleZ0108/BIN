/*
Q: "����
һ����n���ˣ���1--n��ţ���Ѽ�Ҫ��Ƭ�����Ѽ�ֻ�ܰ���Ƭ�����е�k���ˡ�
�ѼѰ��������ǵĹ�ϵ�û��ĳ̶ȸ�ÿ���˸�����һ����ʼȨֵW[i]��
Ȼ�󽫳�ʼȨֵ�Ӵ�С��������ÿ�˾�����һ�����D[i]��ȡֵͬ����1--n����
���������Ŷ�10ȡģ��ֵ����Щ�˷�Ϊ10�ࡣ
Ҳ����˵����ÿ���˵�������C[i]��ֵΪ(D[i]-1) mod 10 +1����Ȼ�����ŵ�ȡֵΪ1--10��
��i����˽������õ�E[i]��Ȩֵ��
����Ҫ���ľ���������϶���Ȩֵ�Ժ����յ�Ȩֵ����k���ˣ���������ǵı�š�
�������У�������˵�W[i]��ͬ�����С�����ȡ�

��ʽ
�����ʽ
��һ������ÿո�����������������ֱ���n��k��

�ڶ��и�����10�����������ֱ���E[1]��E[10]��

�����и�����n������������i������ʾ���Ϊi���˵�ȨֵW[i]��

�����ʽ
ֻ�����һ���ÿո������k���������ֱ��ʾ���յ�W[i]�Ӹߵ��͵��˵ı�š�"
*/
//��ؼ���������㷨

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

	//����������� 
	//Ȩֵ�������
	//���Ȩֵ��ͬ ���С������
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