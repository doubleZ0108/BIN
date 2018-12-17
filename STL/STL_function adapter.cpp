/*
STL --- function adapter
* binder
* negator
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

void binder(vector<int> &ivec)
{
	/*求大于2的个数*/
	int num1 = count_if(ivec.begin(), ivec.end(), bind2nd(greater<int>(), 2));
	cout << "num1 is " << num1 << endl;

	/*求奇数的个数*/
	int num2 = count_if(ivec.begin(), ivec.end(), bind2nd(modulus<int>(), 2));
			//modulus adapter返回 (elem % 第二个参数)
	cout << "num2 is " << num2 << endl;
}
void negator(vector<int> &ivec)
{
	/*在上面的基础上 求偶数的个数*/
	int num3 = count_if(ivec.begin(), ivec.end(), not1(bind2nd(modulus<int>(), 2)));
	cout << "num3 is " << num3 << endl;
}

int main(void)
{
	vector<int> ivec = { 1,6,3,8,0,2,7,4,9,5 };
	/*
	绑定器(binder):
	* binder通过把二元函数对象的一个实参绑定到一个特殊的值上，将其转换成一元函数对象。
	* C++标准库提供两种预定义的binder适配器，bind1st和bind2nd
	* 前者把值绑定到二元函数对象的第一个实参上，后者绑定到第二个实参上。
	*/
	binder(ivec);

	/*
	取反器(negator):negator是一个将函数对象的值翻转的函数适配器。
	* 标准库提供两个预定义的negator适配器
	* not1翻转一元预定义函数对象的真值，而not2翻转二元谓词函数的真值
	*/
	negator(ivec);

	system("pause");
	return 0;
}