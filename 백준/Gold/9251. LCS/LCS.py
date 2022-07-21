str_1 = input()
str_2 = input()

dp = [[0]*(len(str_2)+1) for _ in range(len(str_1)+1)]

for i,a in enumerate(str_1,1):
  for j,b in enumerate(str_2,1):
    if a == b:
      dp[i][j] = dp[i-1][j-1] + 1
    else:
      dp[i][j] = max(dp[i-1][j], dp[i][j-1])
print(max(map(max, dp)))