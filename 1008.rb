c = [?R, ?T, ?L, ?B]
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
h = {?R=>0, ?T=>1, ?L=>2, ?B=>3}

s = gets.split.map { |x| x.to_i }
if s.size == 1 ;
	n = s[0]
	x, y = gets.split.map { |x| x.to_i }
	print x, ' ', y, ?\n
	q = [[x, y]]
	map = Array.new(11) { Array.new(11) { false } }
	vis = Array.new(11) { Array.new(11) { false } }
	vis[x][y] = map[x][y] = true

	(n-1).times do
		x, y = gets.split.map { |x| x.to_i }
		map[x][y] = true;
	end

	while q.size != 0 do
		t = q.shift
		0.upto(3) do |k|
			if map[t[0]+dx[k]][t[1]+dy[k]] && !vis[t[0]+dx[k]][t[1]+dy[k]] ;
				print c[k]
				vis[t[0]+dx[k]][t[1]+dy[k]] = true;
				q <<= [t[0]+dx[k], t[1]+dy[k]]
			end
		end
		if q.size == 0 ;
			print ?., ?\n
		else
			print ?,, ?\n
		end
	end
else
	x, y = s
	ans = [[x, y]]
	t = 0
	while gets do
		$_[0..-3].each_char do |c|
			# print t, ' ', c, ' ', h[c], ?\n
			ans <<= [ans[t][0]+dx[h[c]], ans[t][1]+dy[h[c]]]
		end
		t += 1
	end

	ans.sort!
	print ans.size, ?\n
	ans.each do |p|
		print p[0], ' ', p[1], ?\n
	end
end