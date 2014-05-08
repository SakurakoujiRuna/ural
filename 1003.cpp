#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

const int N = 12111;

int l[N], r[N];
int c[N];

struct DS
{
	int p[N],d[N];
	inline DS() { }
	inline void clear(int id)
	{
		for(int i=0;i<id;i++)
			p[i] = i, d[i] = 0;

	}
	inline int find(int x)
	{
		if(x == p[x])
			return x;
		int ret = find(p[x]);
		d[x] ^= d[p[x]];
		return p[x] = ret;
	}
	inline bool query(int a, int b)
	{
		//cout << find(a) << find(b) << '\n';
		return find(a) == find(b);
	}
	inline void merge(int a, int b, int id)
	{
		int t = find(b);
		p[t] = a;
		d[t] = id^d[b];
	}

}A;

int main()
{
	ios::sync_with_stdio(false);
	while(true)
	{
		int len; cin >> len;
		if(len == -1) break;
		int n; cin >> n;
		map <int, int> M;
		bool flag = false;
		for(int i=0;i<n;i++)
		{
			string s;
			cin >> l[i] >> r[i] >> s;
			if(l[i]<0 || r[i]>len)
			{
				if(!flag)
					cout << i << '\n';
				flag = true;
			}
			if(s == "odd")
				c[i] = 1;
			else c[i] =0;
			r[i]++; M[l[i]] = M[r[i]] = 0;
		}
		if(flag) continue;
		int id = 0;
		for(map<int,int>::iterator it=M.begin();it!=M.end();it++)
			M[it->first] = id++;
		int ans = n;
		A.clear(id);
		for(int i=0;i<n;i++)
		{
			l[i] = M[l[i]];
			r[i] = M[r[i]];
			if(A.query(l[i],r[i]) && (A.d[l[i]]^A.d[r[i]])!=c[i])
			{
				ans = i; break;
			}
			else if(!A.query(l[i],r[i]))
				A.merge(l[i],r[i],c[i]);
			/*
			for(int i=0;i<id;i++)
				cout << i << ' ' << A.p[i] << ' ' << A.d[i] << '\n';
				*/	
		}
		cout << ans << '\n';
	}
	return 0;
}