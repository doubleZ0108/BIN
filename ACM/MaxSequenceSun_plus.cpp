/*
小H给你一个数组{a}，要求支持以下两种操作：
1.  0 l r(1<=l<=r<=n)，询问区间[l,r]中权值和最大的有效子区间的权值和，一个子区间被认为是有效的当且仅当这个子区间中没有两个相邻的偶数或者奇数。
2.  1 x v(1<=x<=n,-109<=v<=109)，将a[x]的值修改为v。

输入描述:
第一行读入两个正整数n,m(1<=n,m<=105)
第二行读入n个整数，第i个表示a[i](-109 <= a[i] <= 109)
接下来m行，每行三个数表示操作，描述见题目描述。

输出描述:
输出每个询问的答案。

示例1
10 10
-9 -8 -8 -8 2 -7 -5 2 2 3 
0 3 5
0 4 4
0 2 4
1 6 6
1 1 6
1 5 9
0 1 2
1 5 -8
0 2 4
1 3 -2
输出

2
-8
-8
6
-8
*/

#include <bits/stdc++.h>
using namespace std;
#define INFINITE -(1<<30)
 
int main(void)
{
    int n,m;    cin>>n>>m;
    vector<long long> arr(n);
    for(int i=0;i<n;++i)//{cin>>arr[i];}
    
    {
        scanf("%llf",&arr[i]);
    }
 
    int op;
    while(m--)
    {
        scanf("%d",&op);
        if(op==0)
        {
            int l,r;
            scanf("%d %d",&l,&r);
             
            l--;r--;
            long long ThisSum = 0, MaxSum = INFINITE;
            for (int i = l; i <= r; ++i)
            {
                ThisSum += arr[i];
 
 
                if (ThisSum > MaxSum) { MaxSum = ThisSum; }
                else if (ThisSum < 0 ||
                        (i!=r && (arr[i]+arr[i+1])%2==0))
                {
                    ThisSum = 0;
                }
            }
             
            printf("%lld\n",MaxSum);
             
        }
        else{
            long long x,v;
            scanf("%lld %lld",&x,&v);
            arr[x-1]=v;
        }
    }
     
     
    return 0;
}
