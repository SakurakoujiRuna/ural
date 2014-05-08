#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 52111;
int f[N];
string word[N];

int toi[] = {2, 2, 2,
			 3, 3, 3,
			 4, 4,
			 1, 1,
			 5, 5,
			 6, 6,
			 0, 7, 0,
			 7, 7,
			 8, 8, 8,
			 9, 9, 9,
			 0};

int main()
{
	ios::sync_with_stdio(false);
	while(true)
	{
		string s;
		cin >> s;
		if(s == "-1")
			break;
		int n;
		cin >> n;
		int m = s.size();
		for(int i=0;i<n;i++)
			cin >> word[i];
		memset(f,0x3f,sizeof(f));
		f[m] = 0;
		for(int i=m;i>0;i--)
			for(int j=0;j<n;j++)
				if(word[j].size() <= i)
				{
					bool flag = true;
					int len = word[j].size();
					for(int k=0;k<len;k++)
						if(toi[word[j][k]-'a'] != s[i-len+k]-'0')
						{
							//cout << i << ' ' << j << ' ' << toi[word[j][k]-'a'] << ' ' << i-len+k << '\n';
							flag = false; break;
						}
					if(flag)
					{
						f[i-len] = min(f[i-len], f[i]+1);
						//cout << i << ' ' << j << '\n';
					}
				}
		if(f[0] > 100)
			cout << "No solution.\n";
		else
		{
			int t = 0;
			while(t != m)
				for(int i=0;i<n;i++)
					if(word[i].size()+t <= m)
					{
						bool flag = true;
						int len = word[i].size();
						for(int k=0;k<len;k++)
							if(toi[word[i][k]-'a'] != s[t+k]-'0')
								flag = false;
						if(flag && f[t]==f[t+len]+1)
						{
							cout << word[i] << ' ';
							t = t+len; break;
						}
					}
			cout<<'\n';
		}
	}
	return 0;
}