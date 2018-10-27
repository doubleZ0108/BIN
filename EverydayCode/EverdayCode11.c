#include <stdio.h>
#include <stdlib.h>
int BinarySearch(int arr[], int size, int key)
//别忘了二分查找必须要求数组有序
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
			return mid + 1;
		}
	}
	return -1;
}
int main(void)
{
	int arr[] = { -42,-25,-10,-5,0,2,34,57,98,1246,7654,9865,11111, };
	int size = sizeof(arr) / sizeof(arr[0]);

	int key = 11111;
	int result = BinarySearch(arr, size, key);
	printf(result == -1 ? "Sorry, key is not in the array" : "The index of key is %d", result);

	

	system("pause");
	return 0;
}