/*
  https://ac.nowcoder.com/acm/problem/14615
  
  自己的算法和标程的思路完全一样
  一直没AC的原因在于素数表开的不够大, 导致ssNum后期求得不对, 如果强行开很大又会内存爆掉
  正确做法应该是检测如果三部分的某一项超过n就可以不再填充ssNum了
  最后还要记得去重
*/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MaxSize 10000

void growPrime(vector<int> &prime, int MaxNum = 2e6+10) 
{
	vector<bool> flag(MaxNum, false);

	int len = 0;
	for (int i = 2; i < MaxNum; i++)
	{
		if (!flag[i])
		{
			prime[len++] = i;

			if (len == MaxSize) { return; }

			for (int j = 2 * i; j < MaxNum; j += i)
			{
				flag[j] = true;
			}
		}
	}
}

int main(void)
{
	LL n;    cin >> n;

	vector<int> prime(MaxSize);   //打一个素数表
	growPrime(prime);

	vector<LL> ssNum;
	int a, b, c;

	for (int i = 0; i<MaxSize; ++i)
	{
		a = pow(prime[i],4);    //一直没AC的原因
        if(a>n){break;}
        
		for (int j = 0; j<MaxSize; ++j)
		{
			b = pow(prime[j],3)+a;
            if(b>n){break;}
            
			for (int k = 0; k<MaxSize; ++k)
			{
				c = pow(prime[k],2)+b;
                if(c>n){break;}
                
				ssNum.push_back(c);
			}
		}
	}

	sort(ssNum.begin(), ssNum.end());
	ssNum.erase(unique(ssNum.begin(), ssNum.end()), ssNum.end());   //排序后要去重, 否则无法AC

	cout << upper_bound(ssNum.begin(), ssNum.end(), n) - ssNum.begin() << endl;

	return 0;
}
