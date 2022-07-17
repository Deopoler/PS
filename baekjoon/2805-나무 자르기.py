N,M = map(int, input().split())
woods = list(map(int, input().split()))

start = 1
end = max(woods)
result = 0

def check(value):
  if sum(map(lambda x: x-value if x>value else 0, woods)) >= M:
    return True
  return False

while start <= end:
  mid = (start + end) // 2

  if (check(mid)):
    result = mid
    start = mid+1
  else:
    end = mid-1

print(result)