/*
STL --- sort
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <ctime>
#include <functional>
using namespace std;

#define MaxSize 50

class myClass
{
	friend ostream& operator<<(ostream& os, const myClass &buf);

public:
	int x, y;

	myClass() = default;
	myClass(int bufx,int bufy):x(bufx),y(bufy){}

	bool operator<(const myClass &buf) const
	{ return this->x < buf.x; }
};

bool myless(const myClass &cl1, const myClass &cl2)
{
	return (cl1.y < cl2.y);
}

void Sort_for_myClass(vector<myClass> sequence)
{
	
	cout << "Before sort: ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;

	sort(sequence.begin(), sequence.end());
	cout << "After sort(compartion funct -> class): ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;

	sort(sequence.begin(), sequence.end(), myless);
	cout << "After sort(compartion funct -> global function): ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;
}

void mySort(vector<myClass> sequence)
{
	sort(sequence.begin(), sequence.end());
	cout << "After sort(): ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;
}
void myStableSort(vector<myClass> sequence)
{
	stable_sort(sequence.begin(), sequence.end());
	cout << "After stable_sort(): ";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;
}
void test_StableSort(vector<myClass> sequence)
{
	cout << "Before sort:";
	for_each(sequence.begin(), sequence.end(), [](myClass n) {cout << n << ' '; });
	cout << endl;

	mySort(sequence);
	myStableSort(sequence);
}



int main(void)
{
	srand(time(NULL));
	vector<myClass> sequence(MaxSize);
	for (int i = 0; i < MaxSize; ++i)
	{
		sequence[i].x = rand() % MaxSize;
		sequence[i].y = rand() % MaxSize;
	}

	/*sort对自定义的类做排序的两种方法*/
	//sort采用的是成熟的"快速排序算法"
	//(目前大部分STL版本已经不是采用简单的快速排序，而是结合内插排序算法)。
	//Sort_for_myClass(sequence);

	/*stable_sort STL稳定的排算法序*/
	//stable_sort采用的是"归并排序"
	//test_StableSort(sequence);	

	/*partial_sort 对局部进行排序*/
	//partial_sort采用的堆排序(heapsort)
	//如果希望用partial_sort来实现全排序，只要让middle=last就可以了
	//可以用在 大数据量下找最小的几个数
	//test_PartialSort(sequence);

	/*partial_sort_copy 对新容器大小的数据量进行排序*/
	//partial_sort_copy其实是copy和partial_sort的组合
	//被排序(被复制)的数量是[first, last)和[result_first, result_last)中区间较小的那个
	//如果[result_first, result_last)区间大于[first, last)区间
	//那么partial_sort相当于copy和sort的组合
	//test_PartialSortCopy(sequence);

	system("pause");
	return 0;
}

ostream & operator<<(ostream & os, const myClass & buf)
{
	os << '(' << buf.x << ',' << buf.y << ')';
	return os;
}
