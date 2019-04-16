dp = [[]]

dp.append([])
for j in range(0,10):
	dp[1].append(1)

for i in range(2,66):
	dp.append([])
	for j in range(0,10):
		ans = 0
		for k in range(0,j+1):
			ans=ans+dp[i-1][k]
		dp[i].append(ans)
		
x = int(input())

while(x>0):
	x= x-1
	c = input()
	t = c.split(' ')[0]
	n = int(c.split(' ')[1])
	print(t+ " " +str(dp[n+1][9]))