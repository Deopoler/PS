import sys
input = sys.stdin.readline
INF = int(1e6)

N,M = map(int,input().split())
graph = [[INF for _ in range(N+1)] for __ in range(N+1)]
for i in range(1,N+1):
  graph[i][i] = 0
for _ in range(M):
  a,b = map(int,input().split())
  graph[a][b] = 1
  graph[b][a] = 1

for k in range(1,N+1):
  for i in range(1,N+1):
    for j in range(1,N+1):
      graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j])
      
sum_list = [0]*(N+1)
for i in range(1,N+1):
  for j in range(1,N+1):
    sum_list[j] += graph[i][j]

result_person = []
result_value = INF

for i in range(1,N+1):
  current_value = sum_list[i]
  if current_value < result_value:
    result_value = current_value
    result_person = [i]
  elif current_value == result_value:
    result_person.append(i)

print(result_person[0])