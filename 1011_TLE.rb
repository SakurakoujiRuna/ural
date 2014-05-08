p = gets.to_f
q = gets.to_f

ans = 2
while true do
	ip = ans*p/100 + 1e-10
	iq = ans*q/100 - 1e-10
	if (ip.round>ip&&ip.round<iq) || ((ip.round+1)>ip&&(ip.round+1)<iq) ;
		print ans, ?\n
		break
	end
	ans += 1
end