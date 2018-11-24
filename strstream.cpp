/*
C++���ַ������Ķ�д
	(1)���̺���ʾ�����ǰ��ַ���ʽ����������豸,�ڴ��е��������������ʾ��֮ǰ,Ҫ��ת��ΪASCII����ʽ
		�Ӽ��������������ASCII����ʽ���뵽���뻺����,�ڸ�������ǰת��Ϊ��Ӧ�������͵Ķ�������ʽ,Ȼ�󸳸�����
	(2)�ַ�������������Ĳ����ļ�,�����ڴ��е�һ���ַ�����,��˲���Ҫ�򿪺͹ر��ļ�
	(3)�ļ��������һ���ļ��Ľ�����,���ַ���û��,�û�Ҫָ��һ�������ַ���Ϊ������

	(4)��������ַ�����,ֻ�ܴ��ַ�������������ַ�,�����ܰ��������͵�������ʽ��ȡ����
	(5)���ַ������������ַ������൱���ڴ��е���ʱ�ֿ�,������ļ�ʹ�÷���,���ؽ����ļ�
		��ȡ�ٶȿ�,����������������ֻ������ģ����,���ֻ����Ϊ��ʱ�Ĵ洢�ռ�
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

	ostrstream strout(str, 50);	//Ҫ�ѵڶ����������õĹ���,Ҫ��Ȼ�����β����������

	for (int i = 0; i < 3; ++i)
	{
		strout << stu[i].num << ' ' << stu[i].name << ' ' << stu[i].score << ' ';
	}
	strout << ends;		//ends��C++��I/O������, ����һ��'\\0\

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

	sort(&arr[0], &arr[9]);		//��arr����,���°����������д��str��

	ostrstream strout(str, sizeof(str));
	for (int i = 0; i < 10; ++i)
	{
		strout << arr[i] << ' ';
	}
	strout << ends;		//���������

	cout << "after I/O str: " << str << endl;
}

int main(void)
{
	/*��������ַ���������*/
	char str1[20];
	ostrstream strout(str1, 20, ios::out);

	/*���������ַ���������*/
	char str2[20];
	istrstream strin(str2);		
		//ʡ�Եڶ���������ζ��,�ַ�����str2�е�ȫ��������Ϊ�����ַ�����������

	/*������������ַ���������*/
	char str3[20];
	strstream strio(str3, sizeof(str3), ios::in | ios::out);


	/*���뵽�ַ�������*/
	strInput();

	/*���ַ����������������*/
	charArr_to_intArr();

	system("pause");
	return 0;
}