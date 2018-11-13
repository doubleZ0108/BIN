/*
		C++输入输出专题
	在C++的输入输出中, 编译系统对数据类型进行严格的检查, 凡是类型不正确的数据都不可能通过编译
	C++的I/O操作是 type safe的, 也是可扩展的

	(1)cin,cout并不是C++提供的语句,他们是iostream类的对象
	(2)iostream-通用输入输出流	fstream-输入输出文件流	strstream输入输出字符串流类

*/

#include <iostream>
#include <cstdlib>
#include <iomanip>	//输出控制符的头文件

using namespace std;

void cinANDcout()
{
	cout << endl << "double test" << endl;
	double a = 123.456789012345;
	//以9位有效数字输出
	cout << setprecision(9) << a << endl;

	//以9位小数输出
	cout << setiosflags(ios::fixed) << setprecision(9) << a << endl;
	cout << resetiosflags(ios::fixed);	//使用后会记忆的, 所以使用过setiosflags要reset

										//科学计数法输出
	cout << setiosflags(ios::scientific) << a << endl;
	cout << resetiosflags(ios::scientific);

	cout << endl << "int test" << endl;
	int b = 1234;
	//十六进制输出
	cout << hex << b << endl;
	//八进制
	cout << oct << b << endl;
	//十进制
	cout << dec << b << endl;

	//设定字段宽度
	cout << setw(10) << b << endl;

	//设置填充字符
	cout << setfill('*') << setw(10) << b << endl;
	cout << setfill(' ');

	//输出正数时给出+号
	cout << setiosflags(ios::showpos) << b << endl;
	cout << resetiosflags(ios::showpos);

	//输出数据左对齐
	cout << setiosflags(ios::left) << setw(10) << b << endl;
	cout << resetiosflags(ios::left);
}
void Comprehense()
{
	/*用控制符控制输出格式*/
	cout << endl << "This is a comprehension of cin and cout" << endl;
	int a = 34;
	cout << "hex:" << hex << a << endl;			//十六进制
	cout << "oct:" << setbase(8) << a << endl;	//八进制
	cout << "dec:" << dec << a << endl;			//十进制形式输出整数

	char pt[] = "China";
	cout << setw(10) << pt << endl;					//字符串的宽度为10
	cout << setfill('*') << setw(10) << pt << endl;	//指定宽度,空白用'*'填充

	double pi = 22.0 / 7.0;
	cout << setiosflags(ios::scientific) << setprecision(8);	//按指数形式输出,8位小数
	cout << "pi=" << pi << endl;
	cout << "pi=" << setprecision(4) << pi << endl;				//改为4位小数
	cout << resetiosflags(ios::scientific);
	cout << "pi=" << setiosflags(ios::fixed) << pi << endl;		//改为小数形式输出

	/*用流对象的成员函数控制输出格式*/
	cout.unsetf(ios::dec);
	cout.setf(ios::hex);
	cout << "hex:" << a << endl;
	cout.unsetf(ios::hex);

	cout.width(10);
	cout << pt << endl;
	cout.fill('*');
	cout << pt << endl;

	cout.setf(ios::scientific);
	cout << pi << endl;
	cout.unsetf(ios::scientific);
	cout.precision(6);
	cout << pi << endl;
}

int main(void)
{
	/*cin cout*/
	//(1)不能使用cin把空格字符和回车换行符作为字符输入给字符变量, 它们将被跳过
	//	 如果想把他们两个输入个字符变量, 可以使用getchar函数
	//(2)width()和setw()只对其后的第一项输入项有效
	//	 例如cout<<setw(6)<<20<<3.14<<endl; 20前面会有4个空格,3.14按系统默认的宽度输出(数据实际长度)
	//(3)使用setf和setiosflags后,如果想设置为同组的另一种状态,要先用unsetf或resetionsflags
	//	 在设置其他状态,否则系统仍然按之前的设置输出
	//(4)用setf设置格式状态时,可以用委员算符|组合多个格式状态(原因是ios类被定义为枚举值)
	//	 如 cout.setf(ios::internal | ios::showpos);

	cinANDcout();
	Comprehense();	//cin和cout的综合应用

	

	/*cerr流对象*/
	//cerr流已被指定为与显示器关联, 也就意味着cerr流中的信息只能在显示器输出
	//在调试程序时, 往往不希望程序运行时的出错信息被送到其他文件, 而要求在显示器上及时输出
	//这是应使用cerr
	//并且cerr是不经过缓冲区的, 直接向显示器上输出有关信息


	/*流成员函数put输出单个字符*/
	//put成员函数也可以用ostream类的其他流对象调用

	cout << endl << "put: " << endl;
	cout.put(71).put(79).put(79).put(68).put('\n');


	//倒序输出字符串
	char str[] = "hello";
	for (int i = 4; i >= 0; --i)
	{
		cout.put(*(str + i));
	}
	cout.put('\n');


	system("pause");
	return 0;
}