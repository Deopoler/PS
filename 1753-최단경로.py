import sys
import heapq

input = sys.stdin.readline
INF = int(1e9) # 무한을 의미하는 값으로 1억 설정

V, E = map(int, input().split()) # 노드의 개수, 간선의 개수

start = int(input())

graph = [[] for _ in range(V+1)] # 그래프 초기화

distance = [INF] * (V+1) # 최단거리를 저장할 리스트

for _ in range(E):
  a,b,c = map(int, input().split())
  # a에서 b까지 가중치 c
  graph[a].append((b,c))

def dijkstra(start):
  q = []

  #시작 지점까지 거리 0
  heapq.heappush(q, (0, start))
  distance[start] = 0

  while q:
    dist, now = heapq.heappop(q)

    if distance[now] < dist:
      continue

    for i in graph[now]:
      cost = dist + i[1]
      if cost < distance[i[0]]:
        distance[i[0]] = cost
        heapq.heappush(q, (cost, i[0]))

dijkstra(start)

for i in range(1, V+1):
  if distance[i] == INF:
    print("INF")
  else:
    print(distance[i])