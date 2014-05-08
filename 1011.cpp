#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	double p, q; cin >> p >> q;
	for(int i=2;;i++)
	{
		double ip = i*p/100+1e-10;
		double iq = i*q/100-1e-10;
		int t = (int)ip;
		if((t>ip && t<iq) || ((t+1)>ip && (t+1)<iq))
		{
			cout << i << '\n';
			break;
		}
	}	
	return 0;
}
