/*
STL --- function adapter
* binder
* negator
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

void binder(vector<int> &ivec)
{
	/*�����2�ĸ���*/
	int num1 = count_if(ivec.begin(), ivec.end(), bind2nd(greater<int>(), 2));
	cout << "num1 is " << num1 << endl;

	/*�������ĸ���*/
	int num2 = count_if(ivec.begin(), ivec.end(), bind2nd(modulus<int>(), 2));
			//modulus adapter���� (elem % �ڶ�������)
	cout << "num2 is " << num2 << endl;
}
void negator(vector<int> &ivec)
{
	/*������Ļ����� ��ż���ĸ���*/
	int num3 = count_if(ivec.begin(), ivec.end(), not1(bind2nd(modulus<int>(), 2)));
	cout << "num3 is " << num3 << endl;
}

int main(void)
{
	vector<int> ivec = { 1,6,3,8,0,2,7,4,9,5 };
	/*
	����(binder):
	* binderͨ���Ѷ�Ԫ���������һ��ʵ�ΰ󶨵�һ�������ֵ�ϣ�����ת����һԪ��������
	* C++��׼���ṩ����Ԥ�����binder��������bind1st��bind2nd
	* ǰ�߰�ֵ�󶨵���Ԫ��������ĵ�һ��ʵ���ϣ����߰󶨵��ڶ���ʵ���ϡ�
	*/
	binder(ivec);

	/*
	ȡ����(negator):negator��һ�������������ֵ��ת�ĺ�����������
	* ��׼���ṩ����Ԥ�����negator������
	* not1��תһԪԤ���庯���������ֵ����not2��ת��Ԫν�ʺ�������ֵ
	*/
	negator(ivec);

	system("pause");
	return 0;
}