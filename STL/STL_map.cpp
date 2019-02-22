/*
STL --- map
*/
#include <iostream>
#include <cstdlib>
#include <string>
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


	/*获得map中的元素*/
		//只有当map中有这个键值的时候这种方法才能获取该元素
		//如不存在会自动创建一个实例,值为初始化值
		string tmpstr = mymap[0];


	/*查询某个键值是否存在*/
		//find
		int destKey = 2;
		map<int, string>::iterator iter = mymap.find(destKey);
		if (iter == mymap.end()) {
			//没找到
		}
		else {
			cout << "关键码是" << iter->first << endl;
			cout << "存储的数据是" << iter->second << endl;
		}

	system("pause");
	return 0;
}