/*
��ԭ����д��������ʱ��, ��������ֵ�ֵ
[a,b]��f(x)�Ļ��� ���Ƶ��� ������������������n����, ������ֵ������ƽ��*������
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
	cout << "�������������: ";
	cin >> a >> b;


	srand(time(0));
		//mmp srand()����ÿһ��ѭ��֮ǰ��һ��, �����������������һ��

	for (int i = 0; i < MaxSize; ++i)
	{
		buf = 1.0*rand() / RAND_MAX * (b - a) + a;
			//[a,b]�����ڵ����������

		//printf("%f ", buf);
		sum += f(buf);
	}

	printf("the integration is %.10f\n", (b - a)*1.0*sum / MaxSize);

	system("pause");
	return 0;
}