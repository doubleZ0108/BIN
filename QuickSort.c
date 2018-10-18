#include <stdio.h>
#include <stdlib.h>

void QuickSort(int *i, int *j)
{
	int *low = i, *high = j;
	int key = *i;

	if (i >= j) { return; }

	while (i < j)
	{
		while (i < j && *j >= key) { --j; }
		if (*j < key)
		{
			*i = *j;
			++i;
		}

		while (i < j && *i <= key) { ++i; }
		if (*i > key)
		{
			*j = *i;
			--j;
		}
	}

	*i = key;

	QuickSort(low, i - 1);
	QuickSort(i + 1, high);
}
int main(void)
{
	int arr[] = { 34524,-7654,0,235,-42,-56,24,46,35,124,5,24,7,12,47,2,2,75,0,0,-756,-45, };
	int size = sizeof(arr) / sizeof(arr[0]);

	QuickSort(arr, arr + size - 1);

	for (int *parr = arr; parr < arr + size; ++parr)
	{
		printf("%d ", *parr);
	}

	system("pause");
	return 0;
}