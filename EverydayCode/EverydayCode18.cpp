#include <iostream>
#include <cstdlib>
using namespace std;

int BinarySearch(int arr[], int size, int key)
{
	int low = 0, high = size - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] > key)
		{
			high = mid - 1;
		}
		else if (arr[mid] < key)
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
int* BinarySearch_RECURSE(int *low, int *high, int key)
{
	if (low > high) { return NULL; }
	
	int *mid = low + (high - low) / 2;
	if (*mid > key) {
		BinarySearch_RECURSE(low, mid - 1, key);
	}
	else if (*mid < key)
	{
		BinarySearch_RECURSE(mid + 1, high, key);
	}
	else
	{
		return mid;
	}

}
int main(void)
{
	int arr[] = { -34,-12,-9,0,1,5,9,12,14,23,57,98,1235,6578, };
	int size = sizeof(arr) / sizeof(arr[0]);

	int key;
	cout << "Please enter a number you want to find: ";
	cin >> key;

	if (BinarySearch(arr, size, key) == -1)
	{
		cout << "the num " << key << " is not found!" << endl;
	}
	else
	{
		cout << "the position is " << BinarySearch(arr, size, key) << endl;
	}

	cout << endl << "******************************" << endl;
	if (BinarySearch_RECURSE(&arr[0], &arr[size - 1], key) == NULL)
	{
		cout << "the num " << key << " is not found!" << endl;
	}
	else
	{
		cout << "the position is " << BinarySearch_RECURSE(&arr[0], &arr[size - 1], key)-arr << endl;
	}

	system("pause");
	return 0;
}