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
	struct Student
	{
		char name[20];
		int num;
		int age;
		char sex;
	};

	Student stu[3] = { {"Li",1001,18,'f'},{"Zhang",1002,19,'m'},{"Gui",1003,17,'f'} };
	ofstream outfile("student.txt", ios::binary);
	if (!outfile)
	{
		cerr << "open student.txt error!" << endl;
		abort();			//���ú�exit()��ͬ
	}

	//���������ʽ

	/*for (int i = 0; i < 3; ++i)
	{
		outfile.write((char*)(&stu[i]), sizeof(stu[i]));
	}*/
	outfile.write((char*)&stu[0], sizeof(stu));

	outfile.close();


	ifstream infile("student.txt", ios::binary);
	if (!infile)
	{
		cerr << "open student.txt error!" << endl;
		abort();			//���ú�exit()��ͬ
	}

	Student save[3];
	/*for (int i = 0; i < 3; ++i)
	{
		infile.read((char*)&save[i], sizeof(save[i]));
	}*/
	infile.read((char*)&save[0], sizeof(save));
	infile.close();

	for (int i = 0; i < 3; ++i)
	{
		cout << "NO." << i + 1 << endl;
		cout << "name: " << save[i].name << endl;
		cout << "num: " << save[i].num << endl;
		cout << "age: " << save[i].age << endl;
		cout << "sex: " << save[i].sex << endl;
	}
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
	//�������ļ����Լ�������ļ�Ҳ�������ļ� fstream���� ����Ϊios::out|ios::in|ios::binary
	//���кܶ�ƫ�Ƶĺ�����������
	Binaryfile();

	/*�����ƴ�ͼƬ����*/
	//��֪��bug����,������ȫ����
	copypicture();

	system("pause");
	return 0;
}