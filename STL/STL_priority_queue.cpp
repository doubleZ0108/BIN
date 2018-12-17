/*
STL --- priority_queue
* empty()  //������ȶ���Ϊ�գ��򷵻���
* pop()    //ɾ����һ��Ԫ��
* push()   //����һ��Ԫ��
* size()   //�������ȶ�����ӵ�е�Ԫ�صĸ���
*
* top()   //�������ȶ�������������ȼ���Ԫ�� *		Ĭ������ֵ�������ȼ����
*/
#include <iostream>
#include <cstdlib>
#include <vector>		//���ȶ��еĲ���
#include <queue>		//���ȶ���
#include <functional>	//����������adapter
#include <algorithm>
using namespace std;

struct NODE
{
	int data;
	
	bool operator<(const NODE &buf) const		//ע�������const
	{ return this->data < buf.data; }
};
class cmp
{
public:
	bool operator()(const NODE &n1, const NODE &n2)const	//����Ҳ��const
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
	//priority_queue<int> prQueue;		//Ĭ��ʹ�õ���vector��Ϊ������lessΪ������

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

	/*�Զ�������ݽṹ�����Ϊ ���ȶ��еĲ���*/
	prQueue_for_class();

	system("pause");
	return 0;
}