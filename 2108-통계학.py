import sys
input = sys.stdin.readline
n = int(input())

sum_ = 0
counts = [0] * 8001

for _ in range(n):
  x = int(input())
  sum_ += x
  counts[x+4000] += 1

mode = [] #최빈값
mode_count = 0 # 최빈값의 개수
max_value = -4000 # 최댓값
min_value = 4001 # 최솟값
total_count = 0
median = -4001 # 중앙값
for i in range(-4000, 4001):
  index = i + 4000
  count = counts[index]
  if count > mode_count: # 현재 값의 개수가 더 클 경우 최빈값 리스트와 개수를 현재 값으로 초기화
    mode = [i]
    mode_count = count
  elif count == mode_count: #현재 값의 개수와 같을 경우 최빈값 리스트에 현재 값을 추가
    mode.append(i)
  if min_value == 4001 and count > 0:
    min_value = i
  if count > 0:
    max_value = i
  total_count += count
  if total_count - count < (n+1)//2 <= total_count:
    median = i
print(round(sum_ / n))
print(median)
if len(mode) >= 2:
  print(mode[1])
else:
  print(mode[0])
print(max_value - min_value)