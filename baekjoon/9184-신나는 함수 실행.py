import sys

d = [[[-1] * 101 for _ in range(101)] for __ in range(101)]
def w(a,b,c):
  if d[a+50][b+50][c+50] != -1:
    return d[a+50][b+50][c+50]
  if a <= 0 or b <= 0 or c <= 0:
    d[a+50][b+50][c+50] = 1
    return 1

  if a > 20 or b > 20 or c > 20:
    result = w(20, 20, 20)
    d[a+50][b+50][c+50] = result
    return result

  if a < b and b < c:
    result = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
    d[a+50][b+50][c+50] = result
    return result

  result = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
  d[a+50][b+50][c+50] = result
  return result

while True:
  a,b,c = list(map(int, sys.stdin.readline().rstrip().split()))
  if a == b == c == -1:
    break
  print(f"w({a}, {b}, {c}) = {w(a,b,c)}")