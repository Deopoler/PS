import heapq
import sys
input = sys.stdin.readline

heap = []

N = int(input())

for _ in range(N):
  x = int(input())
  if x == 0: # 큰 값을 제거하고 출력
    if len(heap): # 비어있지 않다면 큰 값을 제거하고 출력
      print(-heapq.heappop(heap))
    else: # 비어있다면 0 출력
      print(0)
  else: # 값을 힙에 넣기
    heapq.heappush(heap, -x)