/*
	C++11 => Lambda表达式

	[capture](parameters) mutable ->return-type{ statement }
	* [capture]捕获列表
		1.[var]表示值传递方式捕捉变量var；
		2.[=]表示值传递方式捕捉所有父作用域的变量（包括this）；
		3.[&var]表示引用传递捕捉变量var；
		4.[&]表示引用传递方式捕捉所有父作用域的变量（包括this）；
		5.[this]表示值传递方式捕捉当前的this指针。
		(注意不要 [&, &var] 这种重复捕获

	* (parameters)参数列表: 和正常的函数一样, 调用的时候要传入参数

	* mutable修饰符: 默认情况下，Lambda函数总是一个const函数，mutable可以取消其常量性

	* ->return-type返回类型: 无返回值时此项省略
		此外，在返回类型明确的情况下，也可以省略该部分，让编译器对返回类型进行推导

	* {statement}函数体: 与普通函数一样
		不过除了可以使用参数之外，还可以使用所有捕获的变量。
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
	int a = 5, b = 7;

	//以值传递的形式传递a, 以引用的方式传递b, 此外调用时还需传递参数c
	//函数为mutable, 所以在函数内部才可以对值传递的a进行修改
	//返回值为int
	//由于b是引用类型, 所以调用func()函数后, b的值会改
	//因为此为Lambda表达式, 所以可以直接使用该作用域中的变量a和b
	auto func = [=, &b](int c)mutable->int{++a; ++b; return b + c; };

	cout << func(3) << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	system("pause");
	return 0;
}
