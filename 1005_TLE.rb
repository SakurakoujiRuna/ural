# TLE

n = gets.to_i
f = gets.split.map { |x| x.to_i }

ans = 233333
0.upto((1<<n)-1) do |k|
	t = 0
	0.upto(n-1) do |i|
		if ((k>>i)&1) == 1 ;
			t += f[i]
		else
			t -= f[i]
		end
	end
	ans = [ans, t.abs].min
end

print ans,?\n