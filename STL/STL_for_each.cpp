/*
STL --- for_each()
	for_each(InputIterator first, InputIterator last, Function functor);
	1.��first~last�е�ÿ��Ԫ�ؽ��в���
	2.�º�����ÿ��Ԫ�ؽ��в���
	3.ʱ�临�Ӷ���O(n)
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

void myFunction(int i)
{
	cout << i << ' ';
}

class myClass
{
public:
	//ע��: Ҫ��operator()��Ϊ���к���
	void operator()(int i)
	{
		cout << i << ' ';
	}
};

int main(void)
{
	int arr[3] = { 1,2,3 };
	vector<int> ivec(arr, arr + sizeof(arr) / sizeof(arr[0]));

	/*������������ȫ�ֺ���ָ��*/
	for_each(ivec.begin(), ivec.end(), myFunction);
	cout << endl;

	/*�����������������*/
	for_each(ivec.begin(), ivec.end(), myClass());
	//��������һ������, ������operator()
	cout << endl;

	/*ʹ��lambda���ʽ*/
	for_each(ivec.begin(), ivec.end(), [](int i) {cout << i << ' '; }), cout << endl;

	system("pause");
	return 0;
}