def dfs(graph, v, visited):
  visited[v] = True

  for i in graph[v]:
    if not visited[i]:
      dfs(graph, i, visited)

computers = int(input())
N = int(input())
graph = [[] for _ in range(computers + 1)]
visited = [False] * (computers+1)
for _ in range(N):
  a,b = map(int, input().split())
  graph[a].append(b)
  graph[b].append(a)

dfs(graph, 1, visited)

print(visited.count(True) - 1)