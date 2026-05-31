n, k = map(int, input().split())
MOD = 10**9 + 7

dp = [0] * (n + 1)

dp[1], currSum = 1, 1 

for i in range(2, n + 1):
    dp[i] = currSum
    currSum = (currSum + dp[i]) % MOD
    if i >= k + 1:
        currSum = (currSum - dp[i - k] + MOD) % MOD

print(dp[n])