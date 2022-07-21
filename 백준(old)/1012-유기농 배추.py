T = int(input())

def dfs(graph, x, y, maxX, maxY):
  if x < 0 or x >= maxX or y < 0 or y >= maxY:
    return False
  
  if graph[x][y] == 1:
    graph[x][y] = 0
    dfs(graph, x+1, y, maxX, maxY)
    dfs(graph, x-1, y, maxX, maxY)
    dfs(graph, x, y+1, maxX, maxY)
    dfs(graph, x, y-1, maxX, maxY)
    return True
  else:
    return False



for _ in range(T):
  maxX, maxY, K = map(int, input().split())
  graph = [[0] * maxY for __ in range(maxX)]
  for __ in range(K):
    x,y = map(int, input().split())
    graph[x][y] = 1

  result = 0
  for i in range(maxX):
    for j in range(maxY):
      if dfs(graph, i,j, maxX, maxY) == True:
        result += 1

  print(result)