/*
当原函数写不出来的时候, 近似求积分的值
[a,b]上f(x)的积分 近似等于 在这个区间里随机生成n个点, 做函数值的算术平均*区间宽度
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>

#define MaxSize 10000
using namespace std;

double f(double x)
//f(x) = 0.5x + x^2
{
	return (0.5*x + pow(x, 2));
}

int main(void)
{
	double a, b, sum=0, buf;
	cout << "输入积分上下限: ";
	cin >> a >> b;


	srand(time(0));
		//mmp srand()不能每一次循环之前调一次, 这样会让所有随机数一样

	for (int i = 0; i < MaxSize; ++i)
	{
		buf = 1.0*rand() / RAND_MAX * (b - a) + a;
			//[a,b]区间内的随机浮点数

		//printf("%f ", buf);
		sum += f(buf);
	}

	printf("the integration is %.10f\n", (b - a)*1.0*sum / MaxSize);

	system("pause");
	return 0;
}