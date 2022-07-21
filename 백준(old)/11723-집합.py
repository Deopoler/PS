import sys
input = sys.stdin.readline

M = int(input())

set = [0] * 21

for _ in range(M):
  command = input().split()
  if len(command) == 1:
    command = command[0]
    if command == 'all':
      set = [1] * 21
    elif command == 'empty':
      set = [0] * 21
  else:
    command, x = command
    x = int(x)
    if command == 'add':
      set[x] = 1
    elif command == 'remove':
      set[x] = 0
    elif command == 'check':
      print(set[x])
    elif command == 'toggle':
      set[x] = int(not set[x])