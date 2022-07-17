import sys
input = sys.stdin.readline
N,M = map(int, input().split())

not_listened = set()
not_seen = set()

for _ in range(N):
  not_listened.add(input().rstrip())
for _ in range(M):
  not_seen.add(input().rstrip())

neither_listened_nor_seen = sorted(list(not_listened.intersection(not_seen)))
print(len(neither_listened_nor_seen))
print("""
""".join(neither_listened_nor_seen))