/*
	STL --- assign
	复制一份数据,原容器不变

	或
	重新指定容器大小并对所有元素初始化
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int> old(10);
	for (int i = 0; i < 10; ++i) { old[i] = i; }

	vector<int> fresh(5);
	for (int i = 0; i < 5; ++i) { fresh[i] = 999; }

	/*1. 将区间[first,last)的元素赋值到当前的vector容器中*/
	//会清除掉vector容器中以前的内容
	fresh.assign(old.begin(), old.end());

	for_each(fresh.begin(), fresh.end(), [](int n) {cout << n << ' '; });
	cout << endl;


	/*2. 重新规定容器大小, 并集体初始化为第二个参数*/
	fresh.assign(7, 3);
	for_each(fresh.begin(), fresh.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	system("pause");
	return 0;
}