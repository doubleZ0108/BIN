/*
STL --- set
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <ctime>
#include <functional>
using namespace std;

#define MaxSize 10

int main(void)
{
	srand(time(NULL));
	set<int> S;

	/*向集合中添加元素*/
	//会自动从小到大排序
	for (int i = 0; i < MaxSize; ++i)
	{
		S.insert(rand());
	}
	
	for_each(S.begin(), S.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	/*判断添加元素是否成功*/
	//原集合中有则添加失败; 否则成功
	if (S.insert(3).second)
	{
		cout << "set insert success!" << endl;
	}
	else 
	{
		cout << "set insert failed!" << endl;
	}

	for_each(S.begin(), S.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	system("pause");
	return 0;
}