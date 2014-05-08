n = gets.to_i
p = []
n.times do
	p <<= gets.to_i
end

ans = 1
2.upto(n-1) do |i|
	ans = i if (p[i]-p[i-1]).abs > (p[ans]-p[ans-1]).abs
end

print ans, ' ', ans+1, ?\n
