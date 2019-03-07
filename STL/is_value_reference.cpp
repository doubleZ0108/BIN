/*
is_lvalue_reference / is_rvalue_reference
判断表达式是否为 左/右 值 (究竟什么是左值, 什么是右值还有待深入学习)
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
	int buf = 5;
	int &rbuf = buf;

	cout << is_lvalue_reference<decltype(rbuf)>::value << endl;
	cout << is_rvalue_reference<decltype(rbuf)>::value << endl;

	system("pause");
	return 0;
}
