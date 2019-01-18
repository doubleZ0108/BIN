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

#define MaxSize 10

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

void Sort_for_myClass(void)
{
	srand(time(NULL));
	vector<myClass> sequence(MaxSize);
	for (int i = 0; i < MaxSize; ++i)
	{
		sequence[i].x = rand() % MaxSize;
		sequence[i].y = rand() % MaxSize;
	}
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

int main(void)
{
	/*sort对自定义的类做排序的两种方法*/
	Sort_for_myClass();

	system("pause");
	return 0;
}

ostream & operator<<(ostream & os, const myClass & buf)
{
	os << '(' << buf.x << ',' << buf.y << ')';
	return os;
}
