import sys
input = sys.stdin.readline

for _ in range(int(input())):
  counts = {}
  n = int(input())
  for _ in range(n):
    __, clothes = input().split()
    if clothes in counts:
      counts[clothes] += 1
    else:
      counts[clothes] = 1
  
  result = 1
  count_list = list(counts.values())
  for i in count_list:
    result *= i+1
  print(result-1)