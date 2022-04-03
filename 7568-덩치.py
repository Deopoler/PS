N = int(input())

weights = []
heights = []
for _ in range(N):
  weight, height = map(int, input().split())
  weights.append(weight)
  heights.append(height)
for i in range(N):
  count = 1
  for j in range(N):
    if weights[i] < weights[j] and heights[i] < heights[j]:
      count += 1
  print(count, end=' ')