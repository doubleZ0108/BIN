/*
  https://ac.nowcoder.com/acm/problem/18391
  树中每个节点有一个权值
  求从权值为x到权值为y的路径中最长的长度
  
  没当做树处理, 用的一直是图的算法来求解
*/

//未AC (时间&空间爆掉)
//Floyd算法先把任意两点的距离算出来
//用的时候直接取
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INFINITE 10000    //不能取成1<<30, 数据加的时候会爆的

void Floyd(vector<vector<int> > &D,vector<vector<int> > &G)
{
	int N = G.size();
	for (int k = 0; k < N; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (D[i][k] + D[k][j] < D[i][j])	//从i到j经过k更近
				{
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}

}

int main(void)
{
	int n, q, u, v;    cin >> n >> q;
	vector<LL> c(n);
	for (int i = 0; i<n; ++i) { scanf("%lld", &c[i]); }
	vector<vector<int> > G(n, vector<int>(n, INFINITE));
	for (int i = 0; i<n - 1; ++i) {
		scanf("%d %d", &u, &v);
		u--; v--;
		G[u][v] = G[v][u] = 1;
	}
    
	LL x, y,ans;

	vector<LL> save(c.begin(), c.end());
	sort(save.begin(), save.end());

  vector<vector<int> > D(G.begin(),G.end());
	Floyd(D, G);

	while (q--)
	{
		scanf("%lld %lld", &x, &y);

		if (!binary_search(save.begin(), save.end(), x) || !binary_search(save.begin(), save.end(), y))
    {
        printf("0\n");
    }
		else
		{
			ans = 0;
			for (int i = 0; i<n; ++i)
			{
				if (c[i] == x)
				{
					for (int j = 0; j<n; ++j)
					{
						if (c[j] == y)
						{
							LL buf = D[i][j];

							if (buf>ans) { ans = buf; }
						}
					}
				}
			}
			printf("%lld\n", ans);
		}
	}

	return 0;
}


//bfs (空间&时间爆掉)
LL Way(vector<vector<int> > &G, LL x, LL y)
{
    vector<int> dist(G.size(), -1);
    queue<int> Q;
    Q.push(x);
    dist[x] = 0;
 
    int V;
    while (!Q.empty())
    {
        V = Q.front();    Q.pop();
        for (int W = 0; W<G.size(); ++W)
        {
            if (G[V][W] == 1 && dist[W] == -1)
            {
                dist[W] = dist[V] + 1;
                if (W == y)
                {
                    return dist[y];
                }
                Q.push(W);
            }
        }
    }
 
    return 0;
}
