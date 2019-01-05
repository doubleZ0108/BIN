#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

#define MaxSize 100

int BinarySearch(vector<int> &sequence, int key)
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

	if (BinarySearch(sequence, key) == -1)
	{
		cout << "No such item in the sequence!" << endl;
	}
	else
	{
		cout << "The position is " << BinarySearch(sequence, key) << endl;
	}

	system("pause");
	return 0;
}