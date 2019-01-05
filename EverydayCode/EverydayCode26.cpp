#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

#define MaxSize 100

int BinarySearch(const vector<int> &sequence, int key)
{
	int low = 0, high = MaxSize - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (sequence[mid] > key)
		{
			high = mid - 1;
		}
		else if (sequence[mid] < key)
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int BinarySearch(const vector<int> &sequence, int key, 
	int low, int high)
{
	if (low > high) { return -1; }

	int mid = (low + high) / 2;
	if (sequence[mid] < key)
	{
		BinarySearch(sequence, key, mid + 1, high);
	}
	else if (sequence[mid] > key)
	{
		BinarySearch(sequence, key, low, mid - 1);
	}
	else
	{
		return mid;
	}
}
int main(void)
{
	srand(time(NULL));
	vector<int> sequence(MaxSize);
	for_each(sequence.begin(), sequence.end(), [](int &n) {n = rand(); });
	sort(sequence.begin(), sequence.end());
	for_each(sequence.begin(), sequence.end(), [](int n) {cout << n << ' '; });
	cout << endl;

	int key;
	cout << endl << "Please enter a number you want to find in the sequence: ";
	cin >> key;

	cout << endl << "The while loop version: " << endl;
	if (BinarySearch(sequence, key) == -1)
	{
		cout << "No such item in the sequence!" << endl;
	}
	else
	{
		cout << "The position is " << BinarySearch(sequence, key) << endl;
	}


	cout << endl << "The Recursive version: " << endl;
	if (BinarySearch(sequence, key, 0, MaxSize-1) == -1)
	{
		cout << "No such item in the sequence!" << endl;
	}
	else
	{
		cout << "The position is " << BinarySearch(sequence, key, 0, MaxSize - 1) << endl;
	}

	system("pause");
	return 0;
}