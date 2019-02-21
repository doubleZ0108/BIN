/*
STL --- map
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>
using namespace std;

int main(void)
{
	map<int, string> mymap;

	/*插入元素*/
		//性能不好, 会先去查找括号内的键值是否存在,
		//如果不存在会先创建空对象再赋值(类型为对象类型时效果很糟)
		mymap[1] = "One";
		mymap[2] = "Two";

		//避免开销
		mymap.insert(pair<int,string>(3, "Three"));
		mymap.insert(map<int, string>::value_type(4, "Four"));

	system("pause");
	return 0;
}
