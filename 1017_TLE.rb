n = gets.to_i
f = Array.new(n+1) { Array.new(n+1) { 0 } }

f[0][0] = 1
0.upto(n-1) do |i|
	0.upto(i) do |j|
		(j+1).upto(n-i) do |k|
			f[i+k][k] += f[i][j]
		end
	end
end

ans = -1
f[n].each { |x| ans += x }
print ans, ?\n
