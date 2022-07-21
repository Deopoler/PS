def dfs(graph, v, visited):
  visited[v] = True # 노드 방문처리

  for node in graph[v]: # 노드 v와 연결된 노드를 순환하면서 방문처리 후 dfs함수 재귀 호출
    if not visited[node]:
      dfs(graph, node, visited)


N, M = map(int, input().split())

graph = [[] for _ in range(N+1)]
visited = [False] * (N+1)

for _ in range(M):
  a,b = map(int, input().split())
  graph[a].append(b)
  graph[b].append(a)

if M == 0:
  print(N)
else:
  count = 0
  for node in range(1, N+1):
    if not visited[node]:
      count += 1
      dfs(graph, node, visited)
  
  print(count)