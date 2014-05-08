#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N =121;
const int INF = 0x3f3f3f3f;
int f[N][N];
int map[N][N];
int path[N];

inline void dfs(int x, int t, int n, int& id)
{
	path[id++] = x;
	if(x == t) return;
	for(int i=1;i<=n;i++)
		if(map[x][i]+f[i][t] == f[x][t])
		{
			dfs(i, t, n, id);
			return;
		}
}

int main()
{
	ios::sync_with_stdio(false);
	while(true)
	{
		int n, m;
		cin >> n;
		if(n == -1)
			break;
		cin>>m;
		memset(f,0x3f,sizeof(f));
		for(int i=0;i<m;i++)
		{
			int u, v, x;
			cin >> u >> v >> x;
			if(f[u][v] > x)
				f[u][v] = f[v][u] = x;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				map[i][j] = f[i][j];
		
		int ans = 2333333, id=0;
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<k;i++)
				for(int j=1;j<k;j++)
					if(i!=j && map[k][i]!=INF && map[j][k]!=INF && f[i][j]!=INF && map[k][i]+map[j][k]+f[i][j]<ans)
					{
						id = 0;
						path[id++] = k;
						ans = map[k][i]+map[j][k]+f[i][j];
						//cout << k << ' ' << i << ' ' << j << ' ' << ans << '\n';
						dfs(i, j, n, id);
						path[id++] = j;
					}
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(f[i][k]+f[k][j] < f[i][j])
						f[i][j] = f[i][k]+f[k][j];
		}
		if(!id)
			cout<<"No solution.\n";
		else
		{
			for(int i=0;i<id;i++)
				cout << path[i] << ' ';
			cout<<'\n';
		}
	}
	return 0;
}