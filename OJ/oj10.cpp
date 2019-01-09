/*
Q: "将n个整数存放到一维数组中，试设计一个在时间和空间两方面都尽可能高效的算法
	将该序列循环左移p(0<p<n)个位置
	即由(x0, x1,..., xn-1)变为(xp, xp+1,..., xn-1, x0, x1,..., xp-1)"
*/
//算法思想:
//	先将n个数据原地逆置(xn-1 ,..., xp, xp-1,..., x0)
//	再将前n-p个和后p个元素分别原地逆置得到(xp, xp+1,..., xn-1, x0, x1,..., xp-1)

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
	cout << "请输入循环左移的位置数：";
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