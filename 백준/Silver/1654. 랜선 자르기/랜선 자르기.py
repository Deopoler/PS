K, N = map(int, input().split())

cables=[]
for _ in range(K):
  cables.append(int(input()))

def check(value):
  result = 0
  for cable in cables:
    result += cable // value

  if result >= N:
    return True
  return False

start = 1
end = max(cables)
result = 0

while start <= end:
  mid = (start + end) // 2

  if (check(mid)):
    result = mid
    start = mid+1
  else:
    end = mid-1

print(result)