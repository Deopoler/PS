import sys
input = sys.stdin.readline

d = [1,1,1,2,2] + [0] * 95
for i in range(5,100):
  d[i] = d[i-5] + d[i-1]

for _ in range(int(input())):
  N = int(input())
  print(d[N-1])