/*
题解链接: https://blog.csdn.net/qq_40565977/article/details/82975080

链接：https://ac.nowcoder.com/acm/problem/19820
来源：牛客网

对于每个关卡，原本会以p的概率掉衣服。如果双倍概率，那么会以min(1,2p)的概率掉衣服。
经过统计，栗子米抽了n次一倍掉率的关卡，掉了a次衣服，抽了m次二倍掉率的关卡，掉了b次衣服。能不能告诉栗子米，暖婊真实的掉率最可能是多少。你可以认为在做统计之前，p为一个[0,1]之间的均匀分布。

输入描述:
第一行一个整数T(T≤ 105)，表示数据组数。
每组数据第一行四个整数n,m,a,b(1≤ n,m≤ 109,0≤ a≤ n,0≤ b≤ m)。

输出描述:
对于每组数据，输出一个0到1之间的实数，表示最有可能的概率，保证这个最有可能的概率是良好并且唯一定义的，如果相对误差或者绝对误差在10-9之内那么你的答案被认为是正确的。

示例1
5
3 3 1 2
3 3 0 0
3 3 3 3
5 5 5 0
7 9 2 6
输出
0.3333333333
0.0000000000
1.0000000000
0.2500000000
0.3253523925
*/


#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
const double eps = 1e-10;
double getAnswer(double a, double b, double c) {    double delta = b * b - 4 * a * c;    if (delta <= eps) return 0.5;    delta = sqrt(delta);    double ans = (-b - delta) / (2 * a);    return min(ans, 0.5);}
 
int main(void)
{
    long long T;    cin>>T;
    long long n,m,a,b;
    double p;
     
     
    while(T--)
    {
        scanf("%lld %lld %lld %lld",&n,&m,&a,&b);
         
        if(n==a && m==b){printf("1.0000000000\n");}
        else if(a==0 && b==0){printf("0.0000000000\n");}
        else if(b==m && a*2>=n)
        {
            p=1.0*a/n;
             printf ("%.10f\n",p);
        }
 
        else {
            p = getAnswer(2.0*(n+m), -2*a-b-n-2*m, a+b);
             printf ("%.10f\n",p);
        }
        
    }
     
     
    return 0;
}
