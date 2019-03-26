/*
	STL --- map for myClass
	map用于构造自定义对象
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class myClass
{
	friend ostream &operator<<(ostream &os, const myClass &buf);
private:
	string name;
	int index;

public:
	myClass() = default;
	myClass(string bufname,int bufindex):name(bufname),index(bufindex){}

	bool operator<(const myClass &rhv)const
	{
		return this->index < rhv.index;
	}
};

struct CmpByIndex
{
	bool operator()(const myClass &buf1, const myClass &buf2)const
	{
		return buf1 < buf2;
	}
};

ostream &operator<<(ostream &os, const pair<myClass,int> &buf)
{
	os << buf.first << ' ' << buf.second;
	return os;
}

int main(void)
{
	map<myClass, int> mymap;
	mymap[myClass("zz", 95)] = 1;
	mymap[myClass("yt", 100)] = 2;
	mymap.insert(make_pair(myClass("gf", 88), 3));
	mymap.insert(make_pair(myClass("sm", 73), 4));

	for (auto iter = mymap.begin(); iter != mymap.end(); ++iter)
	{
		cout << *iter << endl;
	}

	system("pause");
	return 0;
}

ostream &operator<<(ostream &os, const myClass &buf)
{
	os << "[" << buf.name << ' ' << buf.index << "]";
	return os;
}
