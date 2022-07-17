N = int(input())

d = [0,1,2] + [0]*(N-1)

for i in range(3,N+1):
  d[i] = d[i-1] + d[i-2]

print(d[N] % 10007)