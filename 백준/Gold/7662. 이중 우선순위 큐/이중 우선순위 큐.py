import heapq
import sys

input = sys.stdin.readline

class Double_Ended_Priority_Queue:
  def __init__(self):
    self.min_heap = []
    self.max_heap = []
    self.counts = {}

  def insert(self, item):
    heapq.heappush(self.min_heap, item)
    heapq.heappush(self.max_heap, -item)
    if item in self.counts:
      self.counts[item] += 1
    else:
      self.counts[item] = 1

  def remove_min(self):
    while self.min_heap:
      min_value = heapq.heappop(self.min_heap)
      if self.counts[min_value]:
        self.counts[min_value] -= 1
        break

  def remove_max(self):
    while self.max_heap:
      max_value = -heapq.heappop(self.max_heap)
      if self.counts[max_value]:
        self.counts[max_value] -= 1
        break

  def get_min(self):
    while self.min_heap:
      min_value = heapq.heappop(self.min_heap)
      if self.counts[min_value]:
        return min_value
    return 'EMPTY'

  def get_max(self):
    while self.max_heap:
      max_value = -heapq.heappop(self.max_heap)
      if self.counts[max_value]:
        return max_value
    return 'EMPTY'

for _ in range(int(input())):
  depq = Double_Ended_Priority_Queue()
  for id in range(int(input())):
    command, n = input().split()
    n = int(n)
    if command == "I": # n을 넣기
      depq.insert(n)
    elif command == 'D': # 값 삭제
      if n == 1: # 최댓값 삭제
        depq.remove_max()
      else: # 최솟값 삭제
        depq.remove_min()
  min_value = depq.get_min()
  max_value = depq.get_max()
  if min_value == 'EMPTY' or max_value == 'EMPTY':
    print('EMPTY')
  else:
    print(max_value, min_value)