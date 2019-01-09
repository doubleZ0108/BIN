/*
Q: "��n��������ŵ�һά�����У������һ����ʱ��Ϳռ������涼�����ܸ�Ч���㷨
	��������ѭ������p(0<p<n)��λ��
	����(x0, x1,..., xn-1)��Ϊ(xp, xp+1,..., xn-1, x0, x1,..., xp-1)"
*/
//�㷨˼��:
//	�Ƚ�n������ԭ������(xn-1 ,..., xp, xp-1,..., x0)
//	�ٽ�ǰn-p���ͺ�p��Ԫ�طֱ�ԭ�����õõ�(xp, xp+1,..., xn-1, x0, x1,..., xp-1)

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void Reverse(int *start, int *end)
{
	int buf;
	for (int *i = start, *j = end; i <= j; ++i, --j)
	{
		swap(*i, *j);
	}
}

int main(void)
{
	int p;
	cout << "������ѭ�����Ƶ�λ������";
	cin >> p;

	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15, };
	int size = sizeof(arr) / sizeof(arr[0]);

	Reverse(&arr[0], &arr[size - 1]);

	Reverse(&arr[0], &arr[size - p - 1]);
	Reverse(&arr[size - p], &arr[size - 1]);

	for_each(arr, arr + size, [](int n) {cout << n << ' '; });

	system("pause");
	return 0;
}