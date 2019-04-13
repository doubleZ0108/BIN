/*
第i个位置的字母在前i个位置中出现了几次？

输入描述:
第一行有2个正整数n，m，分别表示丝带长度和问题个数。
第二行，有n个小写字母，第i个表示丝带第i位的小写字母。
接下来有m行，每行一个正整数 ，表示HtBest的一个问题。

输出描述:
共m行，对于每个问题，给出答案。


示例1
4 4
abba
1
2
3
4
输出
复制
1
1
2
2

示例2
7 7
yyuahhy
7
6
5
4
3
2
1
输出
复制
3
2
1
1
1
2
1
*/

//备忘录算法, 读入数据时就提前把所有位置的结果存储下来
#include <bits/stdc++.h>
using namespace std;
#define LL long long
 
int main(void)
{
   LL n, m;    cin >> n >> m;    getchar();
    vector<char> silk(n);
    vector<int> dict(26, 0);
    vector<LL> result(n);
 
    int pos;
    for (int i = 0; i < n; ++i) {
        scanf("%c", &silk[i]);
        pos = silk[i] - 'a';            //先全部算出来
        dict[pos]++;
        result[i] = dict[pos];
    }
     
    LL now;
    char ch;
    while(m--)
    {
        scanf("%lld",&now);       
        printf("%lld\n",result[now-1]);
    }
     
    return 0;
}



//STL 反复求 (全部运行超时)
long long n,m;    cin>>n>>m;    getchar();
vector<char> silk(n);
for(int i=0;i<n;++i){scanf("%c",&silk[i]);}
     
long long now;
char buf;
while(m--)
{
    scanf("%lld",&now);
    buf=silk[now-1];
    printf("%d\n",count(silk.begin(),silk.begin()+now,buf));
}
