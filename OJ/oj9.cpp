/*
Q: "��֪����Ϊn�����Ա�L����˳��洢�ṹ��
	��дһ��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)���㷨��
	���㷨ɾ�����Ա�������ֵΪx������Ԫ�ء�"

	�ռ临�Ӷ�ΪO(1)��ζ��ֻ����һ������Ĵ洢�ռ䣬��ֻ�ܶ���һ����������ǳ��ô���
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int delNode1(vector<int> sequence, int key, int n)
{
	int cnt = 0;
	for (int i = 0; i < n - cnt; ++i)
	{
		while (sequence[i] == key)
			//��ôдҪע������ɾ, ��ôд����ʱ�临�Ӷ�Ӧ�û���O(n)
		{
			sequence[i] = sequence[n - cnt - 1];	//�ӽ�β���������������Ҳ��key
			++cnt;
		}
	}

	return cnt;
}
int delNode2(vector<int> sequence, int key, int n)
{
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (sequence[i] == key) { cnt++; }
		else
			//�������Ҫɾ��,�Ͱ����ŵ�i-cntλ����ȥ
		{
			sequence[i - cnt] = sequence[i];
		}
	}

	return cnt;
}
int delNode3(vector<int> sequence, int key, int n)
{
	int cnt = 0, pos = 0;				//��������ֻ��һ��pos���У���Ϊ�뷵�������ż��˸�cnt
	for (int i = 0; i < n; ++i)
	{
		if (sequence[i] != key) 
		{ 
			sequence[pos] = sequence[i];
			pos++; 
		}
		else { cnt++; }
	}

	return cnt;
}

int main(void)
{
	vector<int> sequence = { 34,15,78,15,15,15,15,-54,765,124,1,-76,-876,234,15,15,54767,15 };
	
	cout << delNode1(sequence, 15, sequence.size()) << endl;
	cout << delNode2(sequence, 15, sequence.size()) << endl;
	cout << delNode3(sequence, 15, sequence.size()) << endl;

	system("pause");
	return 0;
}