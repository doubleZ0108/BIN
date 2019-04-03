void QuickSort(int arr[], int low, int high)
{
	if (low >= high) { return; }

	int key = arr[low];
	int i = low, j = high;

	while (i < j)
	{
		while (i < j && arr[j] >= key) { --j; }
		if (arr[j] < key) {
			arr[i] = arr[j];
			++i;
		}
		while (i < j && arr[i] <= key) { ++i; }
		if (arr[i] > key) {
			arr[j] = arr[i];
			--j;
		}
	}

	arr[i] = key;

	QuickSort(arr, low, i - 1);
	QuickSort(arr, i + 1, high);
}
