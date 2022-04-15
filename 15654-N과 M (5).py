from itertools import permutations

N,M = map(int, input().split())
lst = sorted(map(int, input().split()))
for i in permutations(lst, M):
  print(*i)