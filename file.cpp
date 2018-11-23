/*
C++文件
	(1)如果在程序运行过程中有些中间结果数据暂时保存在磁盘文件中,以后又需要输入到内存中,
		此时用二进制文件保存是最合适的
*/
#include <iostream>
#include <cstdlib>
#include <fstream>		//支持对磁盘文件的输入输出

using namespace std;

void ASCIIoperate()
{
	int arr[10];
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = i;
	}

	ofstream outfile("test.txt", ios::out);
	if (!outfile)
	{
		cerr << "open error!" << endl;
	}

	for (int i = 0; i < 10; ++i)
	{
		outfile << arr[i] << ' ';
	}

	outfile.close();
}
int main(void)
{
	//要以磁盘文件为对象进行输入输出,必须定义一个文件流类的对象,通过文件流对象将数据从
	//内存输出到磁盘文件,或者通过文件流对象从磁盘文件将数据输入到内存
	//类似于标准输入输出时的cin和cout  (cin和cout已经在iostream中被开发人员事先定义过了)
	ofstream outfile;
	ifstream infile;
	fstream iofile;


	/*打开文件*/
	//(1)为文件流对象和指定的磁盘文件建立关联,以便使文件流流向指定的磁盘文件
	//(2)指定文件的工作方式, 如,该文件时输入文件还是输出文件, ASCII文件还是二进制文件等
	outfile.open("F:\\coding in VS\\EverydayCode\\EverydayCode\\test.txt", ios::out);
		//也可以在定义ofstream对象的时候调动构造函数打开文件
	
	//判断是否打开成功
	if (!outfile)
	{
		cerr << "open error!" << endl;
	}


	/*关闭文件*/
	outfile.close();

	/*C++对ASCII文件的读写操作*/
	ASCIIoperate();



	system("pause");
	return 0;
}