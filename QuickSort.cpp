#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int Partition(vector<int> &ivec, int low, int high)
{
	/*ѡ����׼Ϊ��Ԫ��*/
	int pivotpos = low;
	int pivot = ivec[low];

	for (int i = low + 1; i <= high; ++i)
	{
		if (ivec[i] < pivot && ++pivotpos != i)
			//�����һ��������������ζ�����Ԫ��Ӧ����������׼ǰ��
			//���仰˵, ��׼Ҫ������һ��λ��, �ڳ�һ��λ�ø������С��Ԫ��
			//����++pivotpos
		{
			swap(ivec[i], ivec[pivotpos]);
				//���ڵ�pivotposλ����һ���Ȼ�׼���Ԫ��, �������Ȼ�׼��, ֱ�ӻ�������Ҳ�޷�
				//����һ�ỹҪ�ݹ������ (������Ϊ���ǿ��ŵľ�������
		}
	}

	/*���ѻ�׼��ԭ����lowλ�ðᵽӦ�õ���λ��pivotpos*/
	swap(ivec[low], ivec[pivotpos]);

	/*���ذ�ԭ���з�Ϊ�����ֵ�λ��*/
	return pivotpos;
}
void QuickSort(vector<int> &ivec, int left, int right)
{
	if (left < right)
	{
		/*��pivotposΪ����, �����л��ֳ���������*/
		int pivotpos = Partition(ivec, left, right);	

		/*�ֱ�����Ҳ��ֵݹ����*/
		QuickSort(ivec, left, pivotpos - 1);
		QuickSort(ivec, pivotpos + 1, right);
	}
}

void QuickSort_ever(vector<int> &ivec, int left, int right)
//�趯����
{
	int key = ivec[left];
	int low = left, high = right;

	if (left >= high) { return; }	//ע��Ⱥ�������

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
//ָ�뷽ʽ
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

	//QuickSort(ivec, 0, ivec.size() - 1);	//ע�����������һ������λ��

	//QuickSort_ever(ivec, 0, ivec.size() - 1);

	QuickSort(&ivec[0], &ivec[ivec.size() - 1]);

	for_each(ivec.begin(), ivec.end(), [](int n) {cout << n << ' '; });

	system("pause");
	return 0;
}