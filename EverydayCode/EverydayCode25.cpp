#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

#define MaxSize 100

int Partition(vector<int> &sequence, int low, int high)
{
	int pivotpos = low;
	int pivot = sequence[low];

	for (int i = low + 1; i <= high; ++i)
	{
		if (sequence[i] < pivot && ++pivotpos != i)
		{
			swap(sequence[pivotpos], sequence[i]);
		}
	}

	swap(sequence[pivotpos], sequence[low]);
	
	return pivotpos;
}
void QuickSort(vector<int> &sequence, int left, int right)
{
	if (left < right)
	{
		int pivotpos = Partition(sequence, left, right);
		QuickSort(sequence, left, pivotpos - 1);
		QuickSort(sequence, pivotpos + 1, right);
	}
}

void QuickSort(int *i, int *j)
{
	int *low = i, *high = j;
	int key = *i;

	if (i >= j) { return; }		//递归的终止条件别给忘了

	while (i < j)
	{
		while (i<j && *j>=key) { --j; }
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
	srand(time(NULL));
	vector<int> sequence(MaxSize);
	for_each(sequence.begin(), sequence.end(), [](int &n) {n = rand(); });

	QuickSort(sequence, 0, MaxSize - 1);

	for_each(sequence.begin(), sequence.end(), [](int n) {cout << n << ' '; });

	cout << endl << endl;

	for_each(sequence.begin(), sequence.end(), [](int &n) {n = rand(); });

	QuickSort(&sequence[0], &sequence[MaxSize - 1]);

	for_each(sequence.begin(), sequence.end(), [](int n) {cout << n << ' '; });


	system("pause");
	return 0;
}