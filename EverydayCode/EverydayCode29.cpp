#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

#define MaxSize 7

int Partition(vector<int> &sequence, int low, int high)
{
	int pivotpos = low;
	int pivot = sequence[low];

	for (int i = low + 1; i <= high; ++i)
	{
		if (sequence[i] < pivot && ++pivotpos != i)
		{
			swap(sequence[i], sequence[pivotpos]);
		}
	}

	swap(sequence[low], sequence[pivotpos]);

	return pivotpos;
}
void QuickSort(vector<int> &sequence, int left,int right)
{
	if (left < right)
	{
		int pivotpos = Partition(sequence, left, right);
		QuickSort(sequence, left, pivotpos - 1);
		QuickSort(sequence, pivotpos + 1, right);
	}
}
int main(void)
{
	srand(time(NULL));
	vector<int> sequence(MaxSize);
	for_each(sequence.begin(), sequence.end(), [](int &n) {n = rand(); });
	for_each(sequence.begin(), sequence.end(), [](int n) {cout << n << ' '; });

	QuickSort(sequence, 0, MaxSize-1);

	cout << endl << "after sort: " << endl;
	for_each(sequence.begin(), sequence.end(), [](int n) {cout << n << ' '; });
	system("pause");
	return 0;
}