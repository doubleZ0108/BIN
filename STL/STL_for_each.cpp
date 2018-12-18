/*
STL --- for_each()
	for_each(InputIterator first, InputIterator last, Function functor);
	1.对first~last中的每个元素进行操作
	2.仿函数对每个元素进行操作
	3.时间复杂度是O(n)
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

void myFunction(int i)
{
	cout << i << ' ';
}

class myClass
{
public:
	//注意: 要把operator()设为共有函数
	void operator()(int i)
	{
		cout << i << ' ';
	}
};

int main(void)
{
	int arr[3] = { 1,2,3 };
	vector<int> ivec(arr, arr + sizeof(arr) / sizeof(arr[0]));

	/*第三个参数传全局函数指针*/
	for_each(ivec.begin(), ivec.end(), myFunction);
	cout << endl;

	/*第三个参数传类对象*/
	for_each(ivec.begin(), ivec.end(), myClass());
	//匿名创建一个对象, 并调用operator()
	cout << endl;

	/*使用lambda表达式*/
	for_each(ivec.begin(), ivec.end(), [](int i) {cout << i << ' '; }), cout << endl;

	system("pause");
	return 0;
}