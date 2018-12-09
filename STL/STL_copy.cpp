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
	//copy只负责复制, 不负责开辟空间, 所以要人为的保证空间足够大

	list<int> iList(arr, arr + size);

	cout << "对arr调用copy()输出: ";
	copy(arr, arr + size, ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "对vector调用copy()输出: ";
	copy(iVec.begin(), iVec.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "对list调用copy()输出: ";
	copy(iList.begin(), iList.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}