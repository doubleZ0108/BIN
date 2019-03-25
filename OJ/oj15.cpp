#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Node
{
	int coef;
	int exp;

	Node() = default;
	Node(int bufcoef,int bufexp):coef(bufcoef),exp(bufexp){}
};

int main(void)
{
	vector<Node> poly;
	int coef, exp;
	while (cin >> coef >> exp)
	{
		poly.push_back(Node(coef, exp));
	}
	
	/*常数多项式 (包括零多项式)*/
	if (poly.size() == 1 && poly[0].exp == 0) 
	{
		cout << 0 << ' ' << 0;    //emmmmm此时输出 0 0 emmmmmmm
		return 0;
	}

	if (poly[0].exp != 1)
	{
		cout << poly[0].coef*poly[0].exp << ' ' << poly[0].exp - 1;
	}
	for (int i = 1; i < poly.size(); ++i)
	{
		poly[i].coef *= poly[i].exp;
		poly[i].exp--;

		if (poly[i].exp != -1)
		{
			cout << ' ' << poly[i].coef << ' ' << poly[i].exp;
		}
	}

	system("pause");
	return 0;
}
