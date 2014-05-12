#include <iostream>
#include <cstring>
using namespace std;

const int N = 511;
typedef long long lli;

lli f[N][N];

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	f[0][0] = 1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			for(int k=j+1;k<=n-i;k++)
				f[i+k][k] += f[i][j];
	lli ans = 0;
	for(int i=0;i<n;i++)
		ans += f[n][i];
	cout << ans << '\n';
	return 0;
}