n = int(input())
INF = n
d = [INF] * (n+1)

for i in range(int(n**0.5)+1):
  d[i**2] = 1

for i in range(1, n+1):
  j = 1
  while i - j**2 > 0:
    d[i] = min(d[i], d[i-j**2]+1)
    j += 1

print(d[n])