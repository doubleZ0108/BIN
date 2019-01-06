/*
STL --- binary_search() & upper_bound()
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <ctime>
#include <functional>

using namespace std;

void growSequence(vector<int> &sequence)
{
	const int MaxSize = 100;
	sequence.resize(MaxSize);

	srand(time(NULL));
	for_each(sequence.begin(), sequence.end(), [](int &n) {n = rand(); });
	sort(sequence.begin(), sequence.end());
	for_each(sequence.begin(), sequence.end(), [](int n) {cout << n << ' '; });
	cout << endl;
}

int main(void)
{
	vector<int> sequence;
	growSequence(sequence);

	int key;
	cout << endl << "Please enter a number you want to find in the sequence: ";
	cin >> key;

	/*binary_search()只能判断是否有该元素*/
	cout << endl << "test binary_search(): " << endl;
	if (!binary_search(sequence.begin(), sequence.end(), key))
	{
		cout << "No such item in the sequence!" << endl;
	}
	else
	{
		cout << "The item is in the sequence!" << endl;
	}

	/*upper_bound()返回第一个 大于key 的迭代器*/
	cout << endl << "test upper_bound(): " << endl;
	if (upper_bound(sequence.begin(), sequence.end(), key) == sequence.end())
	{
		cout << "No upper item in the sequence!" << endl;
	}
	else
	{
		cout << "The first position that upperto the key-value is " 
			<< upper_bound(sequence.begin(), sequence.end(), key) - sequence.begin() << endl;
	}

	/*与之对应的是lower_bound()*/
	//返回第一个大于或等于key的迭代器
	cout << endl << "test lower_bound(): " << endl;
	if (lower_bound(sequence.begin(), sequence.end(), key) == sequence.end())
	{
		cout << "No upper or equal item in the sequence!" << endl;
	}
	else
	{
		cout << "The first position that upper or equal to the key-value is " 
			<< lower_bound(sequence.begin(), sequence.end(), key) - sequence.begin() << endl;
	}

	/*变换方向 upper_bound(greater<int>())*/
	//返回第一个小于key的迭代器
	cout << endl << "test upper_bound(greater<int>()): " << endl;
	if (lower_bound(sequence.begin(), sequence.end(), key, greater<int>()) == sequence.end())
	{
		cout << "No lower item in the sequence!" << endl;
	}
	else
	{
		cout << "The first position that lower to the key-value is "
			<< lower_bound(sequence.begin(), sequence.end(), key, greater<int>()) - sequence.begin() << endl;
	}

	/*与之对应的 lower_bound(greater<int>())*/
	//返回第一个小于或等于key的迭代器
	cout << endl << "test lower_bound(greater<int>()): " << endl;
	if (lower_bound(sequence.begin(), sequence.end(), key, greater<int>()) == sequence.end())
	{
		cout << "No lower or equal item in the sequence!" << endl;
	}
	else
	{
		cout << "The first position that lower or equal to the key-value is "
			<< lower_bound(sequence.begin(), sequence.end(), key, greater<int>()) - sequence.begin() << endl;
	}

	system("pause");
	return 0;
}