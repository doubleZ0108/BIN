#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int Partition(vector<int> &ivec, int low, int high)
{
	/*选定基准为首元素*/
	int pivotpos = low;
	int pivot = ivec[low];

	for (int i = low + 1; i <= high; ++i)
	{
		if (ivec[i] < pivot && ++pivotpos != i)
			//如果第一个条件满足则意味着这个元素应当被丢到基准前面
			//换句话说, 基准要往后移一个位置, 腾出一个位置给这个更小的元素
			//所以++pivotpos
		{
			swap(ivec[i], ivec[pivotpos]);
				//现在的pivotpos位置是一个比基准大的元素, 反正它比基准大, 直接换到后面也无妨
				//反正一会还要递归调快排 (个人认为这是快排的净化所在
		}
	}

	/*最后把基准从原来的low位置搬到应该到的位置pivotpos*/
	swap(ivec[low], ivec[pivotpos]);

	/*返回把原序列分为两部分的位置*/
	return pivotpos;
}
void QuickSort(vector<int> &ivec, int left, int right)
{
	if (left < right)
	{
		/*以pivotpos为中心, 把序列划分成两个部分*/
		int pivotpos = Partition(ivec, left, right);	

		/*分别对左右部分递归快排*/
		QuickSort(ivec, left, pivotpos - 1);
		QuickSort(ivec, pivotpos + 1, right);
	}
}

void QuickSort_ever(vector<int> &ivec, int left, int right)
//舞动排序
{
	int key = ivec[left];
	int low = left, high = right;

	if (left >= high) { return; }	//注意等号在这里

	while (left < right)
	{
		while (left < right && ivec[right] >= key)
		{
			--right;
		}
		if (ivec[right] < key)
		{
			ivec[left] = ivec[right];
			++left;
		}

		while (left < right && ivec[left] <= key)
		{
			++left;
		}
		if (ivec[left] > key)
		{
			ivec[right] = ivec[left];
			--right;
		}
	}

	ivec[left] = key;
	QuickSort_ever(ivec, low, left - 1);
	QuickSort_ever(ivec, left + 1, high);
}

void QuickSort(int *left, int *right)
//指针方式
{
	int key = *left;
	int *low = left, *high = right;

	if (left >= high) { return; }

	while (left < right)
	{
		while (left < right && *right >= key)
		{
			--right;
		}
		if (*right < key)
		{
			*left = *right;
			++left;
		}
		while (left < right && *left <= key)
		{
			++left;
		}
		if (*left > key)
		{
			*right = *left;
			--right;
		}
	}

	*left = key;
	QuickSort(low, left - 1);
	QuickSort(left + 1, high);
}

int main(void)
{
	vector<int> ivec = { 23,76,-64,0,-345,-7,-2323,2323,64,876,123,4353, };

	//QuickSort(ivec, 0, ivec.size() - 1);	//注意数组中最后一个数的位置

	//QuickSort_ever(ivec, 0, ivec.size() - 1);

	QuickSort(&ivec[0], &ivec[ivec.size() - 1]);

	for_each(ivec.begin(), ivec.end(), [](int n) {cout << n << ' '; });

	system("pause");
	return 0;
}