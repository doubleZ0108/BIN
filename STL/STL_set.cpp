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

	/*set能包含的最大元素数量*/
	cout <<"max size of set is " << S.max_size() << endl;

	/*
	* equal_range()
	* 返回一对定位器
	* 分别表示第一个大于或等于给定关键值的元素 和 第一个大于给定关键值的元素
	* 这个返回值是一个pair类型
	* 如果这一对定位器中哪个返回失败
	* 就会等于end()的值。
	*/
	pair<set<int>::const_iterator, set<int>::const_iterator> pr;
	pr = S.equal_range(5000);
	cout << "第一个大于等于5000的元素是: " << *pr.first << endl;
	cout << "第一个大于5000的元素是: " << *pr.second << endl;
	
	system("pause");
	return 0;
}