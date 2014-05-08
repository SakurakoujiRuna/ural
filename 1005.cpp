#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int f[23];

int main()
{
	ios::sync_with_stdio(false);
	int n; cin>>n;
	for(int i=0;i<n;i++)
		cin >> f[i];
	int ans = 233333;
	for(int k=0;k<(1<<n);k++)
	{
		int t = 0;
		for(int i=0;i<n;i++)
			if((k>>i)&1)
				t += f[i];
			else t -= f[i];
		ans = min(ans, abs(t));
	}
	cout << ans << '\n';
	return 0;
}