import sys
import heapq
input = sys.stdin.readline

q = []
for _ in range(int(input())):
  x = int(input())
  if x == 0:
    if q:
      print(heapq.heappop(q)[1])
    else:
      print(0)
  else:
    heapq.heappush(q,(abs(x), x))