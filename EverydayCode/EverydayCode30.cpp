#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

int BinarySearch(const vector<int> &sequence, int key)
{
	int low = 0, high = sequence.size() - 1;
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
int main(void)
{
	vector<int> sequence = { 1,3,6,7,8,10,13,15,18,25,36,47,68,89,100 };

	int key;
	cout << "Please enter the key value you want to find in the sequence: ";
	cin >> key;

	if (BinarySearch(sequence, key) != -1)
	{
		cout << "the position of the key valud is ";
		cout << BinarySearch(sequence, key) << endl;
	}
	else
	{
		cout << "not found!" << endl;
	}
	system("pause");
	return 0;
}