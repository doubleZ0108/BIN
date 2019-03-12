/*
	STL --- assign
	����һ������,ԭ��������

	��
	����ָ��������С��������Ԫ�س�ʼ��
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int> old(10);
	for (int i = 0; i < 10; ++i) { old[i] = i; }

	vector<int> fresh(5);
	for (int i = 0; i < 5; ++i) { fresh[i] = 999; }

	/*1. ������[first,last)��Ԫ�ظ�ֵ����ǰ��vector������*/
	//�������vector��������ǰ������
	fresh.assign(old.begin(), old.end());

	for_each(fresh.begin(), fresh.end(), [](int n) {cout << n << ' '; });
	cout << endl;


	/*2. ���¹涨������С, �������ʼ��Ϊ�ڶ�������*/
	fresh.assign(7, 3);
	for_each(fresh.begin(), fresh.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	system("pause");
	return 0;
}