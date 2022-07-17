def dfs(graph, x, y, N, number):
  if x <= -1 or x >= N or y <= -1 or y >= N:
    return False
  
  if graph[x][y] == 1:
    graph[x][y] = number
    dfs(graph, x+1, y, N, number)
    dfs(graph, x-1, y, N, number)
    dfs(graph, x, y+1, N, number)
    dfs(graph, x, y-1, N, number)
    return True

  return False



N = int(input())
graph = []
for _ in range(N):
  graph.append(list(map(int, input())))

number = 2
houses = []
for i in range(N):
  for j in range(N):
    if dfs(graph, i,j, N, number) == True:
      houses.append(sum(x.count(number) for x in graph))
      number += 1

print(len(houses))
for house in sorted(houses):
  print(house)