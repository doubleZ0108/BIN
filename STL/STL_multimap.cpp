/*
	STL --- multimap
	允许key重复, 保存多份数据
*/
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void)
{
	multimap<char, int> multiM;
	multiM.insert(pair<char, int>('z', 19));
	multiM.insert(pair<char, int>('y', 18));
	multiM.insert(pair<char, int>('z', 43));
	multiM.insert(pair<char, int>('z', 67));

	/*equal_range()返回所有key的元组*/
	auto ret = multiM.equal_range('z');
	//输出键值为key的所有元组信息
	for (auto iter = ret.first; iter != ret.second; ++iter)
	{
		cout << iter->first << ' ' << iter->second << endl;
	}

	system("pause");
	return 0;
}
