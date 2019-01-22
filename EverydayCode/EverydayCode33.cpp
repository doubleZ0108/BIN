#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

#define MaxSize 100

void ShellSort(vector<long> &sequence)
{
	for (int gap = sequence.size() / 2; gap >= 1; (gap == 2 ? gap = 1 : gap /= 2.2))
	{
		for (int i = 0; i < gap; ++i)
		{
			for (int j = i + gap; j < sequence.size(); j += gap)
			{
				long temp = sequence[j];
				int k = j;
				while (k - gap >= 0 && temp < sequence[k - gap])
				{
					sequence[k] = sequence[k - gap];
					k -= gap;
				}
				if (k != j)
				{
					sequence[k] = temp;
				}
			}
		}
	}
}

int main(void)
{
	srand(time(NULL));

	vector<long> sequence(MaxSize);
	for (int i = 0; i < MaxSize; ++i) { sequence[i] = rand(); }

	ShellSort(sequence);

	for_each(sequence.begin(), sequence.end() - 1, [](int n) {cout << n << ' '; });
	cout << *(sequence.end() - 1);

	system("pause");
	return 0;
}