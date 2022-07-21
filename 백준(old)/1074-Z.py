N, r, c = map(int, input().split())
result = 0

for i in range(N-1,-1,-1):
  half = 2**i
  if r < half and c < half: # 왼쪽 위
    continue
  elif r < half and c >= half: #오른쪽 위
    result += (half**2)
    c -= half
  elif r >= half and c < half: #왼쪽 아래
    result += 2*(half**2)
    r -= half
  else: #오른쪽 아래
    result += 3*(half**2) 
    c -= half
    r -= half

print(result)