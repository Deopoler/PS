str_1 = input()
str_2 = input()

dp = [[0] * (len(str_2) + 1) for _ in range(len(str_1) + 1)]

for i, a in enumerate(str_1, 1):
    for j, b in enumerate(str_2, 1):
        if a == b:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

result = max(map(max, dp))
print(result)

track = []
current = result
i = len(str_1) - 1
j = len(str_2) - 1
while i >= 0 and j >= 0:
    if dp[i][j + 1] == current:
        i -= 1
    elif dp[i + 1][j] == current:
        j -= 1
    elif dp[i][j] == current - 1:
        track.append(str_1[i])
        i -= 1
        j -= 1
        current -= 1

print("".join(reversed(track)))
