n = gets.to_i
ans = []

if n == 0 ;
	print 10, ?\n
elsif n == 1 ;
	print 1, ?\n
else
	9.downto(2) do |i|
		while n%i == 0 do
			ans <<= i
			n /= i
		end
	end

	if n==1 ;
		print ans.reverse.join, ?\n
	else
		print -1, ?\n
	end
end