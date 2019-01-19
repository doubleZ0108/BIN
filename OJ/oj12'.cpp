/*
Q: "����
һ����n���ˣ���1--n��ţ���Ѽ�Ҫ��Ƭ�����Ѽ�ֻ�ܰ���Ƭ�����е�k���ˡ��ѼѰ��������ǵĹ�ϵ�û��ĳ̶ȸ�ÿ���˸�����һ����ʼȨֵW[i]��Ȼ�󽫳�ʼȨֵ�Ӵ�С��������ÿ�˾�����һ�����D[i]��ȡֵͬ����1--n�������������Ŷ�10ȡģ��ֵ����Щ�˷�Ϊ10�ࡣҲ����˵����ÿ���˵�������C[i]��ֵΪ(D[i]-1) mod 10 +1����Ȼ�����ŵ�ȡֵΪ1--10����i����˽������õ�E[i]��Ȩֵ������Ҫ���ľ���������϶���Ȩֵ�Ժ����յ�Ȩֵ����k���ˣ���������ǵı�š��������У�������˵�W[i]��ͬ�����С�����ȡ�

��ʽ
�����ʽ
��һ������ÿո�����������������ֱ���n��k��

�ڶ��и�����10�����������ֱ���E[1]��E[10]��

�����и�����n������������i������ʾ���Ϊi���˵�ȨֵW[i]��

�����ʽ
ֻ�����һ���ÿո������k���������ֱ��ʾ���յ�W[i]�Ӹߵ��͵��˵ı�š�"
*/
//��Ҫ���ȶ��������㷨 (�����ȶ���Ҳ���Լ��趨��˳��,��ֻ�ǰ��������������ǰ���ԭ��)
//��ʵ����Ҫ���� stable_sort()

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
#include <functional>
using namespace std;

#define INFINITE 1<<30

struct NODE
{
	int W, D, C;
	int name;
};

bool myGreater(const NODE &n1, const NODE &n2)
{
	if (n1.W > n2.W) { return true; }
	else if (n1.W == n2.W && n1.name < n2.name) { return true; }

	return false;
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

	sort(people.begin(), people.end(),myGreater);

	for (int i = 1; i <= n; ++i)
	{
		people[i].D = i;
		people[i].C = (people[i].D - 1) % 10 + 1;
	}

	for (int i = 1; i <= n; ++i)
	{
		people[i].W += E[people[i].C];
	}
	
	sort(people.begin(), people.end(),myGreater);
	

	for (int i = 1; i <= k; ++i)
	{
		cout << people[i].name << ' ';
	}

	system("pause");
	return 0;
}