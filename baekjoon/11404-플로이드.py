import sys
input = sys.stdin.readline
INF = int(1e9) # 무한을 의미하는 값
n = int(input())
m = int(input())
graph = [[INF]*n for _ in range(n)]

for _ in range(m):
  a,b,c = map(int, input().split()) #a에서 b까지 가중치 c
  graph[a-1][b-1] = min(c, graph[a-1][b-1])

for i in range(n):
  graph[i][i] = 0 # 자기 자신으로 가는 가중치 0

for k in range(n):
  for i in range(n):
    for j in range(n):
      graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

for i in range(n):
  for j in range(n):
    if graph[i][j] != INF:
      print(graph[i][j], end=" ")
    else:
      print(0, end=" ")
  print()