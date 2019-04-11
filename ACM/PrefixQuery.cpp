/*
链接：https://ac.nowcoder.com/acm/problem/15706

在一个 Minecraft 村庄中，村长有这一本小写字母构成的名册（字符串的表），
每个名字旁边都记录着这位村民的声望值，而且有的村民还和别人同名。
随着时间的推移，因为没有村民死亡，这个名册变得十分大。
现在需要您来帮忙维护这个名册，支持下列 4 种操作：
1. 插入新人名 si，声望为 ai
2. 给定名字前缀 pi 的所有人的声望值变化 di
3. 查询名字为 sj 村民们的声望值的和（因为会有重名的）
4. 查询名字前缀为 pj 的声望值的和
输入描述:
第一行为两个整数 0 ≤ N ≤ 105，表示接下来有 N 个操作；
接下来 N 行，每行输入一个操作，行首为一个整数 1 ≤ oi ≤ 4，表示这一行的操作的种类，
那么这一行的操作和格式为：
1. 插入人名，这一行的格式为 1 si ai，其中 |ai| ≤ 103
2. 前缀修改声望，这一行的格式为 2 pi di，其中 |di| ≤ 103
3. 查询名字的声望和，这一行的格式为 3 sj
4. 查询前缀的声望和，这一行的格式为 4 pj
输入保证插入人名的字符串的长度和小于或等于 105，总的字符串的长度和小于或等于 106。
输出描述:
对于每一次询问操作，在一行里面输出答案。
示例1
输入
复制
20
1 a -10
1 abcba -9
1 abcbacd 5
4 a
2 a 9
3 aadaa
3 abcbacd
4 a
3 a
2 a 10
3 a
2 a -2
2 d -8
1 ab -2
2 ab -7
1 aadaa -3
4 a
3 abcba
4 a
4 c
输出
复制
-14
0
14
13
-1
9
11
1
11
0
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main(void)
{
	long long N;    cin >> N;
	int op;

	multimap<string, long long> M;

	string name; long long num, total;

	while (N--)
	{
		scanf("%d", &op);
		switch (op)
		{
		case 1:
		{
			cin >> name;
			scanf("%lld", &num);

			M.insert(pair<string, int>(name, num));

			break;
		}
		case 2:
		{
			cin >> name;
			scanf("%lld", &num);

			for (auto &iter : M)
			{
				if (!strncmp(iter.first.c_str(), name.c_str(), name.size()))
				{
					iter.second += num;
				}
			}

			break;
		}
		case 3:
		{
			total = 0;
			cin >> name;

			auto container = M.equal_range(name);
			for (auto iter = container.first; iter != container.second; ++iter)
			{
				total += iter->second;
			}
			printf("%lld\n", total);

			break;
		}
		case 4:
		{
			total = 0;
			cin >> name;

			for (const auto &iter : M)
			{
				if (!strncmp(iter.first.c_str(), name.c_str(), name.size()))
				{
					total += iter.second;
				}
			}
			printf("%lld\n", total);

			break;
		}
		default:break;
		}
	}

	
	system("pause");
	return 0;
}
