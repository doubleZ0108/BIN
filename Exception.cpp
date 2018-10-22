#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>
using namespace std;

void func_inner()
{
	throw "Unknown Exception";
	cout << "[1]This statement will not be excuted" << endl;
}
void func_outer()
{
	func_inner();
	cout << "[2]This statement will not be excuted" << endl;
}

class Base{};
class Derived:public Base{};

int main(void)
{
	string str = "hello world";
	try
	{
		char ch2 = str.at(100);	//at()函数检测到下标越界会抛出一个异常
		cout << ch2 << endl;
	}
	catch (exception &e)
	{
		cout << ".at()out of bound" << endl;
	}

	try
	{
		//try块中调用了某个函数,该函数有调用了另外的一个函数,这个另外的函数抛出了异常
		func_outer();	
		cout << "[3]This statement will not be excuted" << endl;
		/*
		只要抛出了异常,执行流就会沿着函数的调用链王辉退,直到遇到try才停止
		在回退的过程中, 调用链中剩下的代码(所有函数总未被执行的代码), 全都会被跳过
		再也没有执行的机会了
		*/

	}
	catch (const char* e)
	{
		cout << e << endl;
	}

	
	//多级catch
	//这里匹配的是Base, 向上转型
	try
	{
		throw Derived();	//抛出一个Derived类型的匿名数据
		cout << "This statement will not be executed" << endl;
	}
	catch (int)	//这里只指定类型而不给变量
		//只会将异常类型和catch所能处理的类型进行匹配,不会传递异常数据
	{
		cout << "Exception type: int" << endl;
	}
	catch (Base)	//匹配成功, 向上转型
	{
		cout << "Exception type: Base" << endl;
	}
	catch (Derived)
	{
		cout << "Exception type: Derived" << endl;
	}


	system("pause");
	return 0;
}