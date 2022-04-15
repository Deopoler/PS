import sys
from collections import deque
input = sys.stdin.readline

for _ in range(int(input())):
  N, pos = map(int, input().split())
  q = deque(list(map(int, input().split())))
  count = 0
  printed = False
  while not printed:
    max_value = max(q)
    while True:
      importance = q.popleft()
      pos -= 1
      if importance == max_value:
        break
      q.append(importance)
      if pos == -1:
        pos = len(q)-1
        
    if pos == -1:
      printed = True
    count += 1
  print(count)