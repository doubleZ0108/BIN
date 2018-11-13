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

void cinANDcout()
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

	//�趨�ֶο��
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
	cout << setw(10) << pt << endl;					//�ַ����Ŀ��Ϊ10
	cout << setfill('*') << setw(10) << pt << endl;	//ָ�����,�հ���'*'���

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

int main(void)
{
	/*cin cout*/
	//(1)����ʹ��cin�ѿո��ַ��ͻس����з���Ϊ�ַ�������ַ�����, ���ǽ�������
	//	 ��������������������ַ�����, ����ʹ��getchar����
	//(2)width()��setw()ֻ�����ĵ�һ����������Ч
	//	 ����cout<<setw(6)<<20<<3.14<<endl; 20ǰ�����4���ո�,3.14��ϵͳĬ�ϵĿ�����(����ʵ�ʳ���)
	//(3)ʹ��setf��setiosflags��,���������Ϊͬ�����һ��״̬,Ҫ����unsetf��resetionsflags
	//	 ����������״̬,����ϵͳ��Ȼ��֮ǰ���������
	//(4)��setf���ø�ʽ״̬ʱ,������ίԱ���|��϶����ʽ״̬(ԭ����ios�౻����Ϊö��ֵ)
	//	 �� cout.setf(ios::internal | ios::showpos);

	cinANDcout();
	Comprehense();	//cin��cout���ۺ�Ӧ��

	

	/*cerr������*/
	//cerr���ѱ�ָ��Ϊ����ʾ������, Ҳ����ζ��cerr���е���Ϣֻ������ʾ�����
	//�ڵ��Գ���ʱ, ������ϣ����������ʱ�ĳ�����Ϣ���͵������ļ�, ��Ҫ������ʾ���ϼ�ʱ���
	//����Ӧʹ��cerr
	//����cerr�ǲ�������������, ֱ������ʾ��������й���Ϣ


	/*����Ա����put��������ַ�*/
	//put��Ա����Ҳ������ostream����������������

	cout << endl << "put: " << endl;
	cout.put(71).put(79).put(79).put(68).put('\n');


	//��������ַ���
	char str[] = "hello";
	for (int i = 4; i >= 0; --i)
	{
		cout.put(*(str + i));
	}
	cout.put('\n');


	system("pause");
	return 0;
}