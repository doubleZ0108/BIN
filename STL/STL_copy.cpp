#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;
int main(void)
{
	int arr[] = { 23,-87,0,-1,232,3432,98,12,-543,-86 };
	int size = sizeof(arr) / sizeof(arr[0]);

	vector<int> iVec(size);
	copy(arr, arr + size, iVec.begin());
	//copyֻ������, �����𿪱ٿռ�, ����Ҫ��Ϊ�ı�֤�ռ��㹻��

	list<int> iList(arr, arr + size);

	cout << "��arr����copy()���: ";
	copy(arr, arr + size, ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "��vector����copy()���: ";
	copy(iVec.begin(), iVec.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "��list����copy()���: ";
	copy(iList.begin(), iList.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}