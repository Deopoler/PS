import math
T = int(input())

for _ in range(T):
  x,y = map(int, input().split())
  distance = y-x
  n = 1
  An = 1
  while distance >= An:
    An += math.ceil(n/2)
    n += 1

  print(n-1)