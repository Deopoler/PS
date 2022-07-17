import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))
n = int(input())

def dfs(tree, v, visited):
  visited[v] = True
  
  for i in tree[v]:
    if not visited[i]:
      parent[i] = v
      dfs(tree, i, visited)
      
tree = [[] for _ in range(n+1)]
visited = [False] * (n+1)
parent = [-1] * (n+1)
for _ in range(n-1):
  a,b = map(int, input().split())
  tree[a].append(b)
  tree[b].append(a)

dfs(tree, 1, visited)

for i in range(2,n+1):
  print(parent[i])