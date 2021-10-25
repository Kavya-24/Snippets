# Number of ways to reach the nth stair.
def countways(n):
  dp = [0]*(n+1)
  dp[0]=0
  dp[1]=1
  dp[2]=2
  for i in range(3,n+1):
    dp[i]=dp[i-1]+dp[i-2]
  return dp[n]

n=int(input())
print(countways(n))
