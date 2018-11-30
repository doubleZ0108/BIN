/*
		C++�������ר��
	��C++�����������, ����ϵͳ���������ͽ����ϸ�ļ��, �������Ͳ���ȷ�����ݶ�������ͨ������
	C++��I/O������ type safe��, Ҳ�ǿ���չ��

	(1)cin,cout������C++�ṩ�����,������iostream��Ķ���
	(2)iostream-ͨ�����������	fstream-��������ļ���	strstream��������ַ�������

*/

#include <iostream>
#include <cstdlib>
#include <iomanip>	//������Ʒ���ͷ�ļ�

using namespace std;

void cout_usage()
{
	cout << endl << "double test" << endl;
	double a = 123.456789012345;
	//��9λ��Ч�������
	cout << setprecision(9) << a << endl;

	//��9λС�����
	cout << setiosflags(ios::fixed) << setprecision(9) << a << endl;
	cout << resetiosflags(ios::fixed);	//ʹ�ú������, ����ʹ�ù�setiosflagsҪreset

										//��ѧ���������
	cout << setiosflags(ios::scientific) << a << endl;
	cout << resetiosflags(ios::scientific);

	cout << endl << "int test" << endl;
	int b = 1234;
	//ʮ���������
	cout << hex << b << endl;
	//�˽���
	cout << oct << b << endl;
	//ʮ����
	cout << dec << b << endl;

	//�趨�ֶο���
	cout << setw(10) << b << endl;

	//��������ַ�
	cout << setfill('*') << setw(10) << b << endl;
	cout << setfill(' ');

	//�������ʱ����+��
	cout << setiosflags(ios::showpos) << b << endl;
	cout << resetiosflags(ios::showpos);

	//������������
	cout << setiosflags(ios::left) << setw(10) << b << endl;
	cout << resetiosflags(ios::left);
}
void Comprehense()
{
	/*�ÿ��Ʒ����������ʽ*/
	cout << endl << "This is a comprehension of cin and cout" << endl;
	int a = 34;
	cout << "hex:" << hex << a << endl;			//ʮ������
	cout << "oct:" << setbase(8) << a << endl;	//�˽���
	cout << "dec:" << dec << a << endl;			//ʮ������ʽ�������

	char pt[] = "China";
	cout << setw(10) << pt << endl;					//�ַ����Ŀ���Ϊ10
	cout << setfill('*') << setw(10) << pt << endl;	//ָ������,�հ���'*'���

	double pi = 22.0 / 7.0;
	cout << setiosflags(ios::scientific) << setprecision(8);	//��ָ����ʽ���,8λС��
	cout << "pi=" << pi << endl;
	cout << "pi=" << setprecision(4) << pi << endl;				//��Ϊ4λС��
	cout << resetiosflags(ios::scientific);
	cout << "pi=" << setiosflags(ios::fixed) << pi << endl;		//��ΪС����ʽ���

	/*��������ĳ�Ա�������������ʽ*/
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


	//��������ַ���
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
	//����������get����
	char ch;
	while ((ch = cin.get()) != EOF)
		//���ļ�������ʾ��Ϊ�ж�, �������Ҫ���� Ctrl+Z ������ֹ����
	{
		cout.put(ch);
	}

	//��һ��������get
	while (cin.get(ch))
	{
		cout.put(ch);
	}

	//��3��������get
	//cin.get(�ַ�����, �ַ�����n, ��ֹ�ַ�)
	//���������ж�ȡn-1���ַ�, �����n-1���ַ�֮�о�����ָ������ֹ��������ǰ������ȡ
	char arrch[20];
	cin.get(arrch, 10, '\\n');		//ע��˫б��
	cout << arrch << endl;
}
void cin_getline()
{
	cout << endl << "test for getline()" << endl;
	//����: i like C++./i study C++./i am happy.�س� 
	char arrch[20];
	cin >> arrch;
	cout << "1 The string read with cin is: " << arrch << endl;
	//���Ϊ: i
	//cin�����ո�ͽ�����

	cin.getline(arrch, 20, '/');
	cout << "2 The string read with getline(arrch, 20, '/'): " << arrch << endl;
	//���Ϊ: �ո�like C++.
	//(1)���Ǵ�ͷ��,���ǽ��Ŷ�
	//(2)��ֹ�� / �����ŵ�������, ���Ƕ���

	cin.getline(arrch, 20);
	cout << "3 The string read with getline(arrch, 20): " << arrch << endl;
	//���Ϊ: i study C++./i am h
	//����ûָ��������,���� / �������������ַ���ȡ
}

void istream_function()
{
	//eof()�����ж��Ƿ񵽴��ļ�ĩβ, �������������ַ���, ֻ���ж�cin�ĵ�ǰ״̬
	//��. ��������ַ�, �����еķǿո��ַ����
	//��������: C++ is very interesting.�س� Ctrl+Z

	char ch;
	char arrch[20];
	while (!cin.eof())
	{
		if ((ch = cin.get()) != ' ')
		{
			cout.put(ch);
		}
	}

	//peek()���ڹ۲��һ���ַ�,���ǲ�������һ���ַ� (���ڶ���������ָ�벻�ƶ�)
	//��������: ����Ϊasd, ��������cout������ֵ����a
	ch = cin.peek();
	cout << ch;
	cin >> ch;
	cout << ch;

	//putback()���ڰѶ�ȡ���ַ����ص�������, ���뵽��ǰָ��λ��
	//��������: asdf�س�
	//��һ�����a, �ڶ������asdf
	cin >> ch;
	cout << ch << endl;
	cin.putback(ch);
	cin >> arrch;
	cout << arrch << endl;

	//ignore()
	//cin.ignore(n,��ֹ�ַ�) ������������n���ַ�,��������ָ������ֹ�ַ�ʱ��ǰ����
	//Ĭ�ϵ�cin.ignore() �൱�� cin.ignore(1,EOF)
	//��������: 12345678910111213
	//			���Ϊ0111213
	//��������: 1234Asdfg
	//			���Ϊsdfg
	cin.ignore(10, 'A');
	cin >> arrch;
	cout << arrch;
}
int main(void)
{
	/*cout���������*/
	//(1)width()��setw()ֻ�����ĵ�һ����������Ч
	//	 ����cout<<setw(6)<<20<<3.14<<endl; 20ǰ�����4���ո�,3.14��ϵͳĬ�ϵĿ������(����ʵ�ʳ���)
	//(2)ʹ��setf��setiosflags��,���������Ϊͬ�����һ��״̬,Ҫ����unsetf��resetionsflags
	//	 ����������״̬,����ϵͳ��Ȼ��֮ǰ���������
	//(3)��setf���ø�ʽ״̬ʱ,������ίԱ���|��϶����ʽ״̬(ԭ����ios�౻����Ϊö��ֵ)
	//	 �� cout.setf(ios::internal | ios::showpos);

	//cout_usage();
	//Comprehense();	//cin��cout���ۺ�Ӧ��


	/*cin������*/
	//(1)����ʹ��cin�ѿո��ַ��ͻس����з���Ϊ�ַ�������ַ�����, ���ǽ�������
	//	 �����ѿո�ͻس�������ַ�����, ����ʹ��getchar����
	//(2)cin������״̬����һ����ֵ, ����д while(cin>>temp) ��ʱ������õ�cin��ֵ
	//	 ��cin������Ч�ַ��������ļ�������, cin���ڳ���״̬, ֵΪfalse
	//	 ����temp��int����, ���������23.45, ��ôwhile��ִ��һ��, Ȼ���˳�ѭ��




	/*cerr������*/
	//cerr���ѱ�ָ��Ϊ����ʾ������, Ҳ����ζ��cerr���е���Ϣֻ������ʾ�����
	//�ڵ��Գ���ʱ, ������ϣ����������ʱ�ĳ�����Ϣ���͵������ļ�, ��Ҫ������ʾ���ϼ�ʱ���
	//����Ӧʹ��cerr
	//����cerr�ǲ�������������, ֱ������ʾ��������й���Ϣ


	/*����Ա����put��������ַ�*/
	//put��Ա����Ҳ������ostream����������������
	/*cout_put();*/
	
	/*����Ա����get���뵥���ַ�*/
	//cin_get();

	/*getline()����һ���ַ�*/
	//(1)cin<< ��һ��ȡ��������,�������û����ص��Զ�������, ����cin.getline()ֻ�����������ַ�������
	//ע��getline��get�ĵ������÷�������: 
	//getline������ֹ��ʱ����ֹ������
	//get(3����) ������ֹ��������ֹͣ, ��ֹ�������������ĵ�һ����ȡ�ַ�
	//cin_getline();

	/*istream���Ա����*/
	//��Щ��Ա����Ҳ������istream����������������
	//istream_function();

	system("pause");
	return 0;
}