import sys
input = sys.stdin.readline

n = int(input())

d_red = [0]*n
d_green = [0]*n
d_blue = [0]*n

cost_red = []
cost_green = []
cost_blue = []

for _ in range(n):
  r,g,b = map(int,input().split())
  cost_red.append(r)
  cost_green.append(g)
  cost_blue.append(b)

d_red[0]=cost_red[0]
d_green[0]=cost_green[0]
d_blue[0]=cost_blue[0]
for i in range(1,n):
  d_red[i] = min(d_green[i-1], d_blue[i-1]) + cost_red[i]
  d_green[i] = min(d_red[i-1], d_blue[i-1]) + cost_green[i]
  d_blue[i] = min(d_red[i-1], d_green[i-1]) + cost_blue[i]

print(min(d_red[n-1], d_green[n-1], d_blue[n-1]))