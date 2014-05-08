n = gets.to_i
k = gets.to_i
f = Array.new(1801) { Array.new(2) { 0 } }
f[0][1] = 1

0.upto(n-1) do |i|
	f[i+1][0] = f[i][1]
	f[i+1][1] = (k-1)*(f[i][0]+f[i][1])
end

print f[n][1],?\n
