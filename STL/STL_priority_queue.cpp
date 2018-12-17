/*
STL --- priority_queue
* empty()  //如果优先队列为空，则返回真
* pop()    //删除第一个元素
* push()   //插入一个元素
* size()   //返回优先队列中拥有的元素的个数
*
* top()   //返回优先队列中有最高优先级的元素 *		默认是数值最大的优先级最高
*/
#include <iostream>
#include <cstdlib>
#include <vector>		//优先队列的参数
#include <queue>		//优先队列
#include <functional>	//函数适配器adapter
#include <algorithm>
using namespace std;

struct NODE
{
	int data;
	
	bool operator<(const NODE &buf) const		//注意添加了const
	{ return this->data < buf.data; }
};
class cmp
{
public:
	bool operator()(const NODE &n1, const NODE &n2)const	//这里也是const
	{
		return n1 < n2;
	}
};
void prQueue_for_class()
{
	priority_queue<NODE, vector<NODE>, cmp > prQueue;

	NODE node[5];
	node[0].data = 4;
	node[1].data = 1;
	node[2].data = 5;
	node[3].data = 2;
	node[4].data = 3;

	for (int i = 0; i < 5; ++i)
	{
		prQueue.push(node[i]);
	}

	while (!prQueue.empty())
	{
		cout << prQueue.top().data << ' ';
		prQueue.pop();
	}
}

int main(void)
{
	//priority_queue<int> prQueue;		//默认使用的是vector作为容器，less为适配器

	priority_queue<int, vector<int>, greater<int> > prQueue;
	//less
	//less_equal
	//greater
	//greater_equal

	for (int n : {3, 6, 1, 7, 0, 5, 2})
	{
		prQueue.push(n);
	}
	while (!prQueue.empty())
	{
		cout << prQueue.top() << ' ';
		prQueue.pop();
	}

	cout << endl;

	/*自定义的数据结构如何作为 优先队列的参数*/
	prQueue_for_class();

	system("pause");
	return 0;
}