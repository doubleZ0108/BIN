/*
STL --- next_permutation() & prev_permutation()
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

#define MaxSize 4

int main(void)
{
	vector<int> sequence(MaxSize);
	for (int i = 1; i <= MaxSize; ++i)
	{
		sequence[i - 1] = i;
	}

	/*Ѱ���ֵ������һ�����в����*/
	do
	{
		for_each(sequence.begin(), sequence.end(), [](int n) {cout << n << ' '; });
		cout << endl;
	} while (next_permutation(sequence.begin(), sequence.end()));

	cout << endl << "reverse: " << endl;
	/*reverse()���ڷ�ת����*/
	reverse(sequence.begin(), sequence.end());

	/*Ѱ���ֵ������һ�����в����*/
	do
	{
		for_each(sequence.begin(), sequence.end(), [](int n) {cout << n << ' '; });
		cout << endl;
	} while (prev_permutation(sequence.begin(), sequence.end()));
	system("pause");
	return 0;
}