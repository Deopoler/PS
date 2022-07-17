from collections import deque

def bfs(N,K,distance):
  queue = deque([N])

  while queue:
    pos = queue.popleft()
    if pos == K: return

    for i in (pos-1, pos+1, pos*2):
      if 0 <= i <= 200000 and distance[i] == -1:
        distance[i] = distance[pos] + 1
        queue.append(i)

N, K = map(int,input().split())
distance = [-1] * 200001
distance[N] = 0 # 시작점 까지의 거리 0
bfs(N, K, distance)

print(distance[K])