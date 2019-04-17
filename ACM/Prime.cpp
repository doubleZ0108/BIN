#include <bits/stdc++.h>
using namespace std;

#define MaxSize 10000
/*最大值为MaxNum的素数表*/
//如果prime[]被填充满了则提前终止
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
	vector<int> prime(MaxSize);
	growPrime(prime);
	for_each(prime.begin(), prime.end(), [](int n) {cout << n << ' '; });

	system("pause");
	return 0;
}




//最普通的算法
bool isPrime(int num)
{
	if (num == 2 || num == 3) { return true; }
	for (int i = 2; i <= sqrt(num); ++i)
	{
		if (num%i == 0) { return false; }
	}
	return true;
}
void PrimeTable(vector<int> &prime)
{
	prime[0] = 2;    prime[1] = 3;
	int cnt = 2;
	for (LL i = 5;; ++i)
	{
		if (isPrime(i))
		{
			prime[cnt] = i;
			cnt++;
			if (cnt >= prime.size()) { return; }
		}
	}
}
