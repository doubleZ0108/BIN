/*
C++对字符串流的读写
	(1)键盘和显示器都是按字符形式输入输出的设备,内存中的数据在输出到显示器之前,要先转换为ASCII码形式
		从键盘输入的数据以ASCII码形式输入到输入缓冲区,在赋给变量前转换为对应变量类型的二进制形式,然后赋给变量
	(2)字符串流对象关联的不是文件,而是内存中的一个字符数组,因此不需要打开和关闭文件
	(3)文件的最后都有一个文件的结束符,而字符串没有,用户要指定一个特殊字符作为结束符

	(4)如果不用字符串流,只能从字符数组逐个访问字符,而不能按其他类型的数据形式读取数据
	(5)与字符串流关联的字符数组相当于内存中的临时仓库,比外存文件使用方便,不必建立文件
		存取速度快,但是他的生命周期只在所在模块内,因此只能作为临时的存储空间
*/
#include <iostream>
#include <cstdlib>
#include <strstream>
#include <algorithm>

using namespace std;

void strInput()
{
	struct Student
	{
		int num;
		char name[20];
		float score;
	};
	Student stu[3] = { {1001,"Li",45.5},{1002,"Zhang",99.95},{1003,"ZiNing",100.00} };
	char str[50];

	ostrstream strout(str, 50);	//要把第二个参数设置的够大,要不然输出结尾就是烫烫烫

	for (int i = 0; i < 3; ++i)
	{
		strout << stu[i].num << ' ' << stu[i].name << ' ' << stu[i].score << ' ';
	}
	strout << ends;		//ends是C++的I/O操作符, 插入一个'\\0\

	cout << "array str: " << str << endl;
}

void charArr_to_intArr()
{
	char str[50] = "12 34 65 -23 -32 33 61 99 321 32";
	int arr[10];
	
	cout << "array str: " << str << endl;

	istrstream strin(str, sizeof(str));
	for (int i = 0; i < 10; ++i)
	{
		strin >> arr[i];
	}
	
	cout << "array arr: ";
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	sort(&arr[0], &arr[9]);		//将arr排序,重新把有序的序列写会str中

	ostrstream strout(str, sizeof(str));
	for (int i = 0; i < 10; ++i)
	{
		strout << arr[i] << ' ';
	}
	strout << ends;		//插入结束符

	cout << "after I/O str: " << str << endl;
}

int main(void)
{
	/*建立输出字符串流对象*/
	char str1[20];
	ostrstream strout(str1, 20, ios::out);

	/*建立输入字符串流对象*/
	char str2[20];
	istrstream strin(str2);		
		//省略第二个参数意味着,字符数组str2中的全部数据作为输入字符串流的内容

	/*建立输入输出字符串流对象*/
	char str3[20];
	strstream strio(str3, sizeof(str3), ios::in | ios::out);


	/*输入到字符数组中*/
	strInput();

	/*从字符数组里读整型数组*/
	charArr_to_intArr();

	system("pause");
	return 0;
}