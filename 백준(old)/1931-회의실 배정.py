import sys
import operator
input = sys.stdin.readline

N = int(input())

conferences = []

for _ in range(N):
  conferences.append(tuple(map(int, input().split())))


conferences.sort(key = operator.itemgetter(1,0))

prior_conference = (0,0)
count = 0

for start, end in conferences:
  prior_start, prior_end = prior_conference
  if start >= prior_end:
    count += 1
    prior_conference = (start, end)

print(count)