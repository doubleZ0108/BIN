#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;
int main(void)
{
	int arr[3] = { 1,2,3 };

	do
	{
		for_each(arr, arr + 3, [](int i) {cout << i << ' '; }), cout << endl;
	} while (next_permutation(arr, arr + 3));
	//与之对应的是	prev_permutation();


	system("pause");
	return 0;
}