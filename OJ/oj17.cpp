/*
链接：https://ac.nowcoder.com/acm/problem/14291

给你一个长度为n的序列，你每次可以将一个序列分割成两个连续的的子序列，
分割的代价为原序列的总和。
现在允许你在初始时将序列重新排列一次。
问分割成n个长度为1的序列的最大总代价是多少？
输入描述:
第一行一个数n表示原序列的长度；
接下来一行n个数a_i表示原序列的第i个数。
2<=n<=100000
0<=a_i<=10000
输出描述:
一行一个整数表示答案。
示例1
输入
复制
4
3 2 4 1
输出
复制
26
说明
[3,2,4,1]重排->[1,2,3,4]->[1],[2,3,4]->[1],[2],[3,4]->[1],[2],[3],[4]。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    long long N;    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;++i){cin>>arr[i];}
     
    sort(arr.begin(),arr.end());
     
    long long total=(N-1)*arr[N-1];
    for(long long i=N-1;i>0;--i)
    {
        total+=i*arr[i-1];
    }
     
    cout<<total<<endl;
    return 0;
}
