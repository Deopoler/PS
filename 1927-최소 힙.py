import sys
import heapq

input = sys.stdin.readline

N = int(input())

heap = []

for _ in range(N):
  x = int(input())
  if x == 0: # 작은 값을 출력하고 삭제
    if not len(heap): # 힙에 원소가 없음
      print(0)
    else:
      print(heapq.heappop(heap))
  else: # 힙에 값을 넣기
    heapq.heappush(heap, x)