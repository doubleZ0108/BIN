/*
有一个字符串S，由加号'+' 和 减号'-'组成
现在要反转一些字符（加号变减号，减号变加号）来使得至多有k个前缀是负平衡的
如果一个前缀的减号数量大于加号数量，我们称这个前缀是负平衡的

输入描述:
第一行输入一个字符串S 
第二行输入一个整数k

输出描述:
输出一个整数

示例1
---
1
输出
1

示例2
+-+-
0
输出
0

示例3
-+-+---
2
输出
1
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    string str;    cin>>str;
    int k;    cin>>k;
     
    int low=0;
    for(int i=0;i<str.size();++i){if(str[i]=='-'){low++;}}
    vector<string> svec(low+1, str);
     
    int cnt=0;
    for(int i=1;i<=low;++i)
    {
        cnt=0;
        for(int j=0;j<str.size();++j)
        {
            if(svec[i][j]=='-')
            {
                ++cnt;
                svec[i][j]='+';
            }
            if(cnt>=i){break;}
        }
    }
     
    int small,big;
   for(int i=0;i<low+1;++i)
   {
       small=big=0;
       cnt=0;
       for(int j=0;j<str.size();++j)
       {
           if(svec[i][j]=='-'){++small;}
           else ++big;
            
           if(small>big){cnt++;}
       }
       if(cnt<=k)
       {
           cout<<i<<endl;
           break;
       }
   }
         
    return 0;
}
