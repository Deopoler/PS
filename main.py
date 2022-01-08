N = int(input())
plan = input().split()

x, y = 1,1

p2d = {'L': 0, 'R': 1, 'U': 2, 'D': 3}
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

for p in plan:
  d = p2d[p]
  x += dx[d]
  y += dy[d]

  if x < 1 or x > N:
    x -= dx[d]
  if y < 1 or y > N:
    y -= dy[d]

print(x,y)