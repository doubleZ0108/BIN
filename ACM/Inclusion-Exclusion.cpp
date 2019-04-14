/*
输入描述:
第一行一个整数t（1<=t<=105）表示有t组数据
接下来t行，每行3个整数n,a,b（1<=a,b,n<=2×109）

输出描述:
对于每一组数据输出一行，每行一个整数表示n以内a或者b倍数的个数
*/

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long t;    cin>>t;
    long long n,a,b;
    long long result;
    while(t--)
    {
        scanf("%lld %lld %lld",&n,&a,&b);
        result=floor(1.0*n/a)+floor(1.0*n/b)-floor(1.0*n/(a*b));
        
        if(a%b==0 || b%a==0)
        {
            result=floor(1.0*n/min(a,b));
        }
        printf("%lld\n",result);
    }
    
    
    return 0;
}
