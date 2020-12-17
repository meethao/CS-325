#!/usr/bin/python
import random
import time

#W is the bag capacity
#val is the value of the items
#n is the number of itmes
#iw is the items weight of each items
def knapsack_rec(W, iw, val, n):
	if n==0 or W == 0:	#base case
		return 0
	if(iw[n-1] <= W):	#while the items wight greater than the total weight W, give up this one
		return max(val[n-1]+knapsack_rec(W-iw[n-1],iw,val,n-1), knapsack_rec(W,iw,val,n-1)) #pick up the greater items
	else:
		return knapsack_rec(W,iw,val,n-1)


def knapsack_dp(W, iw, val, n):
	#create a dp table, dp[][]
	dp = [[0 for i in range(W+1)] for i in range(n+1)]
	for j in range(n+1):
		for k in range(W+1):
			if j==0 or W==0:
				dp[j][k] = 0;	#base case
			elif iw[j-1] <= k:
				dp[j][k] = max(val[j-1]+dp[j-1][k-iw[j-1]],dp[j-1][k])
			else:
				dp[j][k] = dp[j-1][k]
	return dp[n][W]

def ramdom_item(n):
	iw = []
	val = []
	for i in range(0,n):
		iw.append(random.randint(1,20))
		val.append(random.randint(1,50))
	return iw , val
	
	
if __name__ == '__main__':
	iw , val = [] , [] 
	n = 10
	W = 100
	for i in range(0, 10):
		N = n + 2*i
		iw, val = ramdom_item(N)

		start_time_rec = time.time()
		Max_rec = knapsack_rec(W, iw, val, N)
		run_time_rec = time.time() - start_time_rec

		start_time_dp = time.time()
		Max_dp = knapsack_dp(W, iw, val, N)
		run_time_dp = time.time() - start_time_dp

		print("N =",N," W =",W," Rec time =",run_time_rec,"	DP time =",run_time_dp, "	Max Rec =",Max_rec, "	Max DP =",Max_dp)






