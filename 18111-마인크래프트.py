import sys
input = sys.stdin.readline

N,M,B = map(int, input().split())
heights = []
max_height = 0
min_height = 256
for _ in range(N):
  heights += list(map(int, input().split()))
  for h in heights:
    if h > max_height:
      max_height = h
    if h < min_height:
      min_height = h

def get_necessary_time(fill_height):
  additional_block = 0
  necessary_block = 0
  for h in heights:
    if fill_height < h:
      additional_block += h - fill_height
    else:
      necessary_block += fill_height - h
  if necessary_block <= B+additional_block:
    return necessary_block + additional_block*2
  else:
    return False

result = -1
result_height = -1
for i in range(min_height, max_height+1):
  necessary_time = get_necessary_time(i)
  if not isinstance(necessary_time, bool) and (result == -1 or necessary_time <= result):
    result = necessary_time
    result_height = i
print(result, result_height)