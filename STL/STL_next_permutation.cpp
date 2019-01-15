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

	/*寻找字典序的下一个序列并输出*/
	do
	{
		for_each(sequence.begin(), sequence.end(), [](int n) {cout << n << ' '; });
		cout << endl;
	} while (next_permutation(sequence.begin(), sequence.end()));

	cout << endl << "reverse: " << endl;
	/*reverse()用于翻转容器*/
	reverse(sequence.begin(), sequence.end());

	/*寻找字典序的上一个序列并输出*/
	do
	{
		for_each(sequence.begin(), sequence.end(), [](int n) {cout << n << ' '; });
		cout << endl;
	} while (prev_permutation(sequence.begin(), sequence.end()));
	system("pause");
	return 0;
}