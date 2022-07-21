from collections import deque

dx = [1,-1,0,0,0,0]
dy = [0,0,1,-1,0,0]
dz = [0,0,0,0,1,-1]

def bfs(graph, startPositions, maxX, maxY, maxZ):
  queue = deque(startPositions)
  while queue:
    x,y,z = queue.popleft()

    for i in range(6):
      nx = x + dx[i]
      ny = y + dy[i]
      nz = z + dz[i]

      if nx < 0 or nx >= maxX or ny < 0 or ny >= maxY or nz < 0 or nz >= maxZ:
        continue
      if graph[nx][ny][nz] == 0:
        graph[nx][ny][nz] = graph[x][y][z] + 1
        queue.append((nx,ny,nz))


M,N,H = map(int, input().split())

graph = [[] for _ in range(H)]
for i in range(H):
  for _ in range(N):
    graph[i].append(list(map(int, input().split())))

tomato_position = []
for i in range(H):
  for j in range(N):
    for k in range(M):
      if graph[i][j][k] == 1:
        tomato_position.append((i,j,k))

bfs(graph, tomato_position, H,N,M)

graph_1d = [item for sublist1 in graph for sublist2 in sublist1 for item in sublist2]

if 0 in graph_1d:
  print(-1)
else:
  print(max(graph_1d)-1)