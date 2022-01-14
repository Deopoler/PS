from collections import deque
from itertools import chain

dx = [1,-1,0,0]
dy = [0,0,1,-1]

def bfs(graph, startPositions, maxX, maxY):
  queue = deque(startPositions)
  while queue:
    x,y = queue.popleft()

    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]

      if nx < 0 or nx >= maxX or ny < 0 or ny >= maxY:
        continue
      if graph[nx][ny] == 0:
        graph[nx][ny] = graph[x][y] + 1
        queue.append((nx,ny))


N,M = map(int, input().split())

graph = []
for _ in range(M):
  graph.append(list(map(int, input().split())))

tomato_position = []
for i in range(M):
  for j in range(N):
    if graph[i][j] == 1:
      tomato_position.append((i,j))

bfs(graph, tomato_position, M,N)

graph_1d = list(chain.from_iterable(graph))

if 0 in graph_1d:
  print(-1)
else:
  print(max(graph_1d)-1)