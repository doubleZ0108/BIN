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

void cout_usage()
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

void cout_put()
{
	cout << endl << "put: " << endl;
	cout.put(71).put(79).put(79).put(68).put('\n');


	//倒序输出字符串
	char str[] = "hello";
	for (int i = 4; i >= 0; --i)
	{
		cout.put(*(str + i));
	}
	cout.put('\n');
}
void cin_get()
{
	cout << endl << "test for get()" << endl;
	//不带参数的get函数
	//char ch;
	//while ((ch = cin.get()) != EOF)
	//	//以文件结束表示作为判定, 所以最后要出入 Ctrl+Z 才能终止程序
	//{
	//	cout.put(ch);
	//}

	////有一个参数的get
	//while (cin.get(ch))
	//{
	//	cout.put(ch);
	//}

	//有3个参数的get
	//cin.get(字符数组, 字符个数n, 终止字符)
	//从输入流中读取n-1个字符, 如果在n-1个字符之中就遇到指定的终止符了则提前结束读取
	char arrch[20];
	cin.get(arrch, 10, '\\n');		//注意双斜杠
	cout << arrch << endl;
}

int main(void)
{
	/*cout输出流对象*/
	//(1)width()和setw()只对其后的第一项输入项有效
	//	 例如cout<<setw(6)<<20<<3.14<<endl; 20前面会有4个空格,3.14按系统默认的宽度输出(数据实际长度)
	//(2)使用setf和setiosflags后,如果想设置为同组的另一种状态,要先用unsetf或resetionsflags
	//	 在设置其他状态,否则系统仍然按之前的设置输出
	//(3)用setf设置格式状态时,可以用委员算符|组合多个格式状态(原因是ios类被定义为枚举值)
	//	 如 cout.setf(ios::internal | ios::showpos);

	//cout_usage();
	//Comprehense();	//cin和cout的综合应用


	/*cin输入流*/
	//(1)不能使用cin把空格字符和回车换行符作为字符输入给字符变量, 它们将被跳过
	//	 如果想把空格和回车输入成字符变量, 可以使用getchar函数
	//(2)cin本身的状态就是一个数值, 所以写 while(cin>>temp) 的时候就是用的cin的值
	//	 当cin遇到无效字符或遇到文件结束符, cin出于出错状态, 值为false
	//	 比如temp是int类型, 我输入的是23.45, 那么while会执行一次, 然后退出循环




	/*cerr流对象*/
	//cerr流已被指定为与显示器关联, 也就意味着cerr流中的信息只能在显示器输出
	//在调试程序时, 往往不希望程序运行时的出错信息被送到其他文件, 而要求在显示器上及时输出
	//这是应使用cerr
	//并且cerr是不经过缓冲区的, 直接向显示器上输出有关信息


	/*流成员函数put输出单个字符*/
	//put成员函数也可以用ostream类的其他流对象调用
	/*cout_put();*/
	
	/*流成员函数get读入单个字符*/
	//
	cin_get();


	system("pause");
	return 0;
}