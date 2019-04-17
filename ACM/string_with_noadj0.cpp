/*
  长度为N的字符串, 并且没有任何两个或两个以上相邻的0
*/

//动态规划
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int N;    cin>>N;
    vector<vector<int> > dp(N+1,vector<int>(2,0));
    dp[1][0]=dp[1][1]=1;
    for(int i=2;i<N+1;++i)
    {
        dp[i][0]=dp[i-1][1];
        dp[i][1]=dp[i-1][0]+dp[i-1][1];
    }
    cout<<dp[N][0]+dp[N][1]<<endl;

    
    return 0;
}

//组合数学
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int N;    cin>>N;
    if(N==1){cout<<1<<endl;}
    else if(N==2){cout<<3<<endl;}
    else{
        long long Fn_1=2,Fn_2=3,Fn;
        for(int i=3;i<=N;++i)
        {
            Fn=Fn_1+Fn_2;
            Fn_1=Fn_2;
            Fn_2=Fn;
        }
        cout<<Fn<<endl;
    }
 
     
    return 0;
}
