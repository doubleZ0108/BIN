/*
C++�ļ�
	(1)����ڳ������й�������Щ�м���������ʱ�����ڴ����ļ���,�Ժ�����Ҫ���뵽�ڴ���,
		��ʱ�ö������ļ�����������ʵ�
*/
#include <iostream>
#include <cstdlib>
#include <fstream>		//֧�ֶԴ����ļ����������

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
	//Ҫ�Դ����ļ�Ϊ��������������,���붨��һ���ļ�����Ķ���,ͨ���ļ����������ݴ�
	//�ڴ�����������ļ�,����ͨ���ļ�������Ӵ����ļ����������뵽�ڴ�
	//�����ڱ�׼�������ʱ��cin��cout  (cin��cout�Ѿ���iostream�б�������Ա���ȶ������)
	ofstream outfile;
	ifstream infile;
	fstream iofile;


	/*���ļ�*/
	//(1)Ϊ�ļ��������ָ���Ĵ����ļ���������,�Ա�ʹ�ļ�������ָ���Ĵ����ļ�
	//(2)ָ���ļ��Ĺ�����ʽ, ��,���ļ�ʱ�����ļ���������ļ�, ASCII�ļ����Ƕ������ļ���
	outfile.open("F:\\coding in VS\\EverydayCode\\EverydayCode\\test.txt", ios::out);
		//Ҳ�����ڶ���ofstream�����ʱ��������캯�����ļ�
	
	//�ж��Ƿ�򿪳ɹ�
	if (!outfile)
	{
		cerr << "open error!" << endl;
	}


	/*�ر��ļ�*/
	outfile.close();

	/*C++��ASCII�ļ��Ķ�д����*/
	ASCIIoperate();



	system("pause");
	return 0;
}