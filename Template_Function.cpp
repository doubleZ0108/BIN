#include <iostream>
#include <cstdlib>
using namespace std;

template<class type>	//������classҲ����
void Swap(type &a, type &b)
{
	type buf;
	buf = a;
	a = b;
	b = buf;
}

template<typename type1,typename type2, typename rttype>	
//������÷��ǲ����Ե�,��Ϊͨ�����������ǲ����ƶϳ�rttype�����͵�
//������Ҫչʾ���Ƕ��ģ�����͵��﷨
rttype Max(type1 a, type2 b)
{
	if (a > b) { return a; }
	else { return b; }
}
int main(void)
{
	int a = 3, b = 4;
	Swap(a, b);	//ע��Swap�����Ĳ�������������,���Ա���ʹ�ñ�����Ϊ����,������ʹ�ó���
	cout << a << ' ' << b << endl;


	int num = 10; double buf = 15.5;
	cout << "max number is " << Max(num, buf) << endl;	//�����Ǵ����

	system("pause");
	return 0;
}