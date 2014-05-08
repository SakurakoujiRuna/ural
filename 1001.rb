include Math
a = []
while gets do
	a += $_.split.map { |x| x.to_i }
end
a.reverse.each do |x|
	printf("%.4f\n",sqrt(x))
end