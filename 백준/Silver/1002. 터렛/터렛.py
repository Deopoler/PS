T = int(input())

for _ in range(T):
  x1, y1, r1, x2, y2, r2 = map(int, input().split())
  distance = ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5
  if distance == 0:
    if r1 == r2:
      print(-1)
    else:
      print(0)
  else:
    if abs(r1 - r2) < distance < r1 + r2:
      print(2)
    elif r1 + r2 == distance or abs(r1 - r2) == distance:
      print(1)
    else:
      print(0)