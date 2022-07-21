N, K = map(int, input().split())

coins = []
for _ in range(N):
  coins.append(int(input()))

result = 0
for coin in coins[::-1]:
  result += K // coin
  K %= coin
print(result)