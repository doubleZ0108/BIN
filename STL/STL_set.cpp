/*
STL --- set
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <ctime>
#include <functional>
using namespace std;

#define MaxSize 10

class myClass
{
	friend ostream &operator<<(ostream &os, const myClass &buf);

public:
	int x, y;
	myClass() = default;
	myClass(int bufx,int bufy):x(bufx),y(bufy){}

	bool operator<(const myClass &buf)const
	{
		return (this->x < buf.x);
	}
};

void Set_for_myClass(void)
{
	srand(time(NULL));

	//��������� < �����
	set<myClass> myset;

	for (int i = 0; i < MaxSize; ++i)
	{
		myset.insert(myClass(rand(), rand()));
	}

	for_each(myset.begin(), myset.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;
}

int main(void)
{
	srand(time(NULL));
	set<int> S;

	/*�򼯺������Ԫ��*/
	//���Զ���С��������
	for (int i = 0; i < MaxSize; ++i)
	{
		S.insert(rand());
	}

	for_each(S.begin(), S.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	/*�ж����Ԫ���Ƿ�ɹ�*/
	//ԭ�������������ʧ��; ����ɹ�
	if (S.insert(3).second)
	{
		cout << "set insert success!" << endl;
	}
	else
	{
		cout << "set insert failed!" << endl;
	}

	for_each(S.begin(), S.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	/*set�ܰ��������Ԫ������*/
	cout <<"max size of set is " << S.max_size() << endl;

	/*
	* equal_range()
	* ����һ�Զ�λ��
	* �ֱ��ʾ��һ�����ڻ���ڸ����ؼ�ֵ��Ԫ�� �� ��һ�����ڸ����ؼ�ֵ��Ԫ��
	* �������ֵ��һ��pair����
	* �����һ�Զ�λ�����ĸ�����ʧ��
	* �ͻ����end()��ֵ��
	*/
	pair<set<int>::const_iterator, set<int>::const_iterator> pr;
	pr = S.equal_range(5000);
	cout << "��һ�����ڵ���5000��Ԫ����: " << *pr.first << endl;
	cout << "��һ������5000��Ԫ����: " << *pr.second << endl;
	
	/*set�����Զ�����*/
	Set_for_myClass();

	system("pause");
	return 0;
}

ostream & operator<<(ostream & os, const myClass & buf)
{
	os << '(' << buf.x << ',' << buf.y << ')';
	return os;
}
