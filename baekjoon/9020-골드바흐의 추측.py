sieve = [True] * 10001

a = int(10000 ** 0.5)
for i in range(2, a + 1):
    if sieve[i] == True: 
        for j in range(i+i, 10001, i): 
            sieve[j] = False

T = int(input())
for _ in range(T):
  n = int(input())
  a,b = n // 2, n // 2
  while True:
    if sieve[a] and sieve[b]:
      break
    a -= 1 
    b += 1

  print(a,b)