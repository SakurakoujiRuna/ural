#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1003;
int sum[N];

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	string s;
	while(cin >> s)
	{
		int m = s.size();
		sum[0] = 0;
		int t = 0;
		for(int i=1;i<=m;i++)
		{
			sum[i] = sum[i-1];
			if(s[i-1] == '1')
			{
				sum[i]++;
				t += i;	
			}
		}
		if(n == m)
		{
			if(t%(n+1) == 0)
				cout << s << '\n';
			else
				for(int i=0;i<m;i++)
					if(s[i]=='1' && (t-i-1)%(n+1)==0)
					{
						s[i] = '0';
						cout << s << '\n';
						break;
					}
		}
		else if(n == m-1)
			for(int i=0;i<m;i++)
				if(s[i]=='0' && (t-(sum[m]-sum[i+1]))%(n+1)==0)
				{
					for(int j=0;j<i;j++)
						cout << s[j];
					for(int j=i+1;j<m;j++)
						cout << s[j];
					cout << '\n';
					break;
				}
				else if(s[i]=='1' && (t-(sum[m]-sum[i+1])-i-1)%(n+1)==0)
				{
					for(int j=0;j<i;j++)
						cout << s[j];
					for(int j=i+1;j<m;j++)
						cout << s[j];
					cout << '\n';
					break;
				}
				else {}
		else
			for(int i=0;i<=m;i++)
				if((t+sum[m]-sum[i])%(n+1) == 0)
				{
					for(int j=0;j<i;j++)
						cout << s[j];
					cout << '0';
					for(int j=i;j<m;j++)
						cout << s[j];
					cout << '\n';
					break;
				}
				else if((t+sum[m]-sum[i]+i+1)%(n+1) == 0)
				{
					for(int j=0;j<i;j++)
						cout << s[j];
					cout << '1';
					for(int j=i;j<m;j++)
						cout << s[j];
					cout << '\n';
					break;
				}
	}
	return 0;
}