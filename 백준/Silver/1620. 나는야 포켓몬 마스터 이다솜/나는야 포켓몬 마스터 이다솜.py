import sys
input = sys.stdin.readline

N,M = map(int, input().split())

name_to_id = dict()
id_to_name = dict()

for i in range(1,N+1):
  name = input().rstrip()
  name_to_id[name] = i
  id_to_name[i] = name

for _ in range(M):
  a = input().rstrip()
  if a.isdigit():
    print(id_to_name[int(a)])
  else:
    print(name_to_id[a])