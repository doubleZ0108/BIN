/*
C++文件
	(1)如果在程序运行过程中有些中间结果数据暂时保存在磁盘文件中,以后又需要输入到内存中,
		此时用二进制文件保存是最合适的
*/
#include <iostream>
#include <cstdlib>
#include <fstream>		//支持对磁盘文件的输入输出

using namespace std;

void ASCIIfile()
{
	int arr[10];
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = i;
	}

	/*输入到文件中*/
	ofstream outfile("test.txt", ios::out);
	if (!outfile)
	{
		cerr << "open error!" << endl;
		exit(-1);
	}

	for (int i = 0; i < 10; ++i)
	{
		outfile << arr[i] << ' ';
	}

	outfile.close();


	/*从文件中读*/
	ifstream infile("test.txt", ios::in | ios::_Nocreate);
		//1. 可以使用 | 来连接多个设定
		//2. nocreate代表,打开一个文件时如果不存在就返回0, 不会不存在的时候新建一个
	if (!infile)
	{
		cerr << "open error!" << endl;
		exit(-1);
	}

	int save[10];
	for (int i = 0; i < 10; ++i)
	{
		infile >> save[i];
		cout << save[i] << ' ';
	}

	infile.close();


	//当然,put() get() getline()等成员函数也都是可以用的
}

void Binaryfile()
{
	

}

void copypicture()
{
	ofstream outfile("copy.jpg", ios::out | ios::binary);
	ifstream infile("forest.jpg", ios::in | ios::_Nocreate | ios::binary);
	if (!outfile)
	{
		cerr << "open copy.jpg failed!" << endl;
		exit(-1);
	}
	if (!infile)
	{
		cerr << "open forest.jpg failed!" << endl;
		exit(-1);
	}

	char buf;
	while (!infile.eof())
	{
		infile >> buf;
		outfile << buf;
	}
	cout << "copy picture forest.jpg success!" << endl;

	outfile.close();
	infile.close();
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
		exit(-1);
	}


	/*关闭文件*/
	outfile.close();

	/*C++对ASCII文件的读写操作*/
	ASCIIfile();

	/*C++对二进制文件的读写操作*/
	Binaryfile();

	/*二进制打开图片复制*/
	//不知道bug在哪,不能完全复制
	copypicture();

	system("pause");
	return 0;
}