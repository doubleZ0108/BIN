#include <iostream>
#include <cstdlib>
using namespace std;
//坑在 模板函数的重载输出操作符必须在类内直接实现

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

	//emmmmm 模板类的重载输出操作符必须在类内实现
	//只在类内声明,在类外实现就是不行 (会有链接错误
	friend ostream& operator<<(ostream& os, const Point<type1, type2> &buf)
	{
		os << "坐标是" << buf.getx() << ' ' << buf.gety();
		return os;
	}
};

int main(void)
{
	Point<float,const char*> point(120.5f, "东经180度");
	cout << point << endl;

	//模板类的指针要注意:new中的类型要保证和定义的类型一致
	Point<int, double> *p = new Point<int, double>(12, 234.5);
	cout << "坐标是" << p->getx() << ' ' << p->gety() << endl;

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

