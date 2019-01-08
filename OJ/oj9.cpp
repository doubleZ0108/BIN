/*
Q: "已知长度为n的线性表L采用顺序存储结构，
	编写一个时间复杂度为O(n),空间复杂度为O(1)的算法，
	该算法删除线性表中所有值为x的数据元素。"

	空间复杂度为O(1)意味着只能有一个额外的存储空间，即只能定义一个变量（粗浅这么理解
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
			//这么写要注意连续删, 这么写好像时间复杂度应该还是O(n)
		{
			sequence[i] = sequence[n - cnt - 1];	//从结尾换过来的这个可能也是key
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
			//如果不是要删的,就把他放到i-cnt位置上去
		{
			sequence[i - cnt] = sequence[i];
		}
	}

	return cnt;
}
int delNode3(vector<int> sequence, int key, int n)
{
	int cnt = 0, pos = 0;				//这里正常只用一个pos就行，因为想返回数量才加了个cnt
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