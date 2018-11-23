/*
C++�ļ�
	(1)����ڳ������й�������Щ�м���������ʱ�����ڴ����ļ���,�Ժ�����Ҫ���뵽�ڴ���,
		��ʱ�ö������ļ�����������ʵ�
*/
#include <iostream>
#include <cstdlib>
#include <fstream>		//֧�ֶԴ����ļ����������

using namespace std;

void ASCIIfile()
{
	int arr[10];
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = i;
	}

	/*���뵽�ļ���*/
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


	/*���ļ��ж�*/
	ifstream infile("test.txt", ios::in | ios::_Nocreate);
		//1. ����ʹ�� | �����Ӷ���趨
		//2. nocreate����,��һ���ļ�ʱ��������ھͷ���0, ���᲻���ڵ�ʱ���½�һ��
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


	//��Ȼ,put() get() getline()�ȳ�Ա����Ҳ���ǿ����õ�
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
		exit(-1);
	}


	/*�ر��ļ�*/
	outfile.close();

	/*C++��ASCII�ļ��Ķ�д����*/
	ASCIIfile();

	/*C++�Զ������ļ��Ķ�д����*/
	Binaryfile();

	/*�����ƴ�ͼƬ����*/
	//��֪��bug����,������ȫ����
	copypicture();

	system("pause");
	return 0;
}