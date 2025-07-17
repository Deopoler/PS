import sys
sys.setrecursionlimit(1000000)
N,M = map(int,input().split())

visited = [[False]*M for _ in range(N)]
graph = [input() for _ in range(N)]

def dfs(row,col):
    if row >= N or row < 0 or col >= M or col < 0 or visited[row][col] or graph[row][col] == "X":
        return
    visited[row][col] = True
    for nr,nc in ((row+1,col), (row-1,col), (row,col+1), (row, col-1)):
        dfs(nr, nc)

for i in range(N):
    for j in range(M):
        if graph[i][j] == "I":
            dfs(i,j)
            break

result = 0
for i in range(N):
    for j in range(M):
        if graph[i][j] == "P" and visited[i][j]:
            result += 1

if result == 0:
    print("TT")
else:
    print(result)