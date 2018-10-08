#include <iostream>
#include <cstdlib>
using namespace std;

template<class type>	//这里用class也可以
void Swap(type &a, type &b)
{
	type buf;
	buf = a;
	a = b;
	b = buf;
}

template<typename type1,typename type2, typename rttype>	
//这里的用法是不可以的,因为通过函数调用是不能推断出rttype的类型的
//这里想要展示的是多个模板类型的语法
rttype Max(type1 a, type2 b)
{
	if (a > b) { return a; }
	else { return b; }
}
int main(void)
{
	int a = 3, b = 4;
	Swap(a, b);	//注意Swap函数的参数类型是引用,所以必须使用变量作为参数,不可以使用常数
	cout << a << ' ' << b << endl;


	int num = 10; double buf = 15.5;
	cout << "max number is " << Max(num, buf) << endl;	//这样是错误的

	system("pause");
	return 0;
}