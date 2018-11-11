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
int main(void)
{
	/*cin cout*/
	//(1)����ʹ��cin�ѿո��ַ��ͻس����з���Ϊ�ַ�������ַ�����, ���ǽ�������
	//	 ��������������������ַ�����, ����ʹ��getchar����
	cout << endl << "double test" << endl;
	double a = 123.456789012345;
	//��9λ��Ч�������
	cout << setprecision(9) << a << endl;	

	//��9λС�����
	cout << setiosflags(ios::fixed) << setprecision(9) << a << endl;
	cout << resetiosflags(ios::fixed);	//ʹ�ú������, ����ʹ�ù�setiosflagsҪreset

	//��ѧ���������
	cout << setiosflags(ios::scientific) << a << endl;


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

	//�������ʱ����+��
	cout << setiosflags(ios::showpos) << b << endl;
	cout << resetiosflags(ios::showpos);

	//������������
	cout << setiosflags(ios::left) << setw(10) << b << endl;
	cout << resetiosflags(ios::left);




	/*cerr������*/
	//cerr���ѱ�ָ��Ϊ����ʾ������, Ҳ����ζ��cerr���е���Ϣֻ������ʾ�����
	//�ڵ��Գ���ʱ, ������ϣ����������ʱ�ĳ�����Ϣ���͵������ļ�, ��Ҫ������ʾ���ϼ�ʱ���
	//����Ӧʹ��cerr
	//����cerr�ǲ�������������, ֱ������ʾ��������й���Ϣ

	system("pause");
	return 0;
}