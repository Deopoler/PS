import sys
input = sys.stdin.readline

N = int(input())
stairs = []
for _ in range(N):
  stairs.append(int(input()))

if N == 1:
  print(stairs[0])
else:
  d = [0]*N
  d[0] = stairs[0]
  d[1] = stairs[0] + stairs[1]
  
  for i in range(2, N):
    d[i] = max(d[i-3]+stairs[i-1], d[i-2]) + stairs[i]
  
  print(d[-1])