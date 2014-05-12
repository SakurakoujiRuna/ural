n = int(raw_input())
f = [[0 for i in range(n+1)]for j in range(n+1)]

f[0][0] = 1
for i in range(n) :
	for j in range(i+1) :
		for k in range(j+1, n-i+1) :
			f[i+k][k] += f[i][j]

ans = 0
for i in range(n) :
	ans += f[n][i]

print ans
