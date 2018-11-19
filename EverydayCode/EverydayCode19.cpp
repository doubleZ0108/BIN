#include <iostream>
#include <cstdlib>
using namespace std;

template<typename type>
int BinarySearch(type arr[], int size, type key)
{
	int low = 0, high = size - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] < key)
		{
			low = mid + 1;
		}
		else if (arr[mid] > key)
		{
			high = mid - 1;
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
	double arr[] = { -12.65,-2.35,0.16,2.54,5.65,8.65,234.56,765.32,999.99,1000.789,5432.45 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int iarr[] = { -99,-65,-12,0,1,14,64,76,87,123,235,567,876,1256,5678,24521 };
	int isize = sizeof(iarr) / sizeof(iarr[0]);

	int key;
	cout << "Please enter a number: ";
	cin >> key;

	int flag = BinarySearch(iarr, isize, key);
	if (flag>-1)
	{
		cout << "the position is " << flag << endl;
	}
	else
	{
		cout << "sorry the num " << key << " is not found!" << endl;
	}

	system("pause");
	return 0;
}