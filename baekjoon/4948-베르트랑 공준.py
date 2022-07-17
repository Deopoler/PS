import sys

while True:
  n = int(sys.stdin.readline().rstrip())
  if n == 0:
    break
  sieve = [True] * ((2*n)+1)
  a = int((2*n) ** 0.5)

  for i in range(2,a+1):
    if sieve[i]:
      for j in range(i+i, (2*n)+1, i):
        sieve[j] = False
  
  count = 0
  for i in range(2,(2*n)+1):
    if sieve[i] and i > n:
      count += 1

  print(count)