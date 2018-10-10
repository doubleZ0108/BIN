#include <iostream>
#include <cstdlib>
using namespace std;
//���� ģ�庯���������������������������ֱ��ʵ��

template<typename type1,typename type2>
class Point
{
private:
	type1 _x;
	type2 _y;
public:
	Point() = default;
	Point(type1 x, type2 y);
	type1 getx() const;
	type2 gety() const;

	//emmmmm ģ����������������������������ʵ��
	//ֻ����������,������ʵ�־��ǲ��� (�������Ӵ���
	friend ostream& operator<<(ostream& os, const Point<type1, type2> &buf)
	{
		os << "������" << buf.getx() << ' ' << buf.gety();
		return os;
	}
};

int main(void)
{
	Point<float,const char*> point(120.5f, "����180��");
	cout << point << endl;

	//ģ�����ָ��Ҫע��:new�е�����Ҫ��֤�Ͷ��������һ��
	Point<int, double> *p = new Point<int, double>(12, 234.5);
	cout << "������" << p->getx() << ' ' << p->gety() << endl;

	system("pause");
	return 0;
}

template<class type1,typename type2>
Point<type1, type2>::Point(type1 x, type2 y)
{
	_x = x;
	_y = y;
}

template<typename type1,typename type2>
type1 Point<type1, type2>::getx() const
{
	return this->_x;
}

template<typename type1,typename type2>
type2 Point<type1,type2>::gety() const
{
	return this->_y;
}

