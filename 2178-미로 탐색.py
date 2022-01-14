from collections import deque

dx = [1,-1,0,0]
dy = [0,0,1,-1]

def bfs(graph, startX, startY, maxX, maxY):
  queue = deque([(startX, startY)])

  while queue:
    x,y = queue.popleft()

    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]

      if nx < 0 or nx >= maxX or ny < 0 or ny >= maxY:
        continue
      if graph[nx][ny] == 0:
        continue
      if graph[nx][ny] == 1:
        graph[nx][ny] = graph[x][y] + 1
        queue.append((nx,ny))

  return graph[maxX-1][maxY-1]

N,M = map(int, input().split())

maze = []
for _ in range(N):
  maze.append(list(map(int, input())))


print(bfs(maze, 0, 0, N, M))