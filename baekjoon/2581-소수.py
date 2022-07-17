M = int(input())
N = int(input())


sieve = [True] * (N+1)

a = int(N ** 0.5)
for i in range(2, a + 1):
    if sieve[i] == True: 
        for j in range(i+i, N+1, i): 
            sieve[j] = False

minimum = -1
result = 0
for i in range(2,N+1):
  if sieve[i] and i >= M:
    if minimum == -1:
      minimum = i
    result += i

if result == 0:
  print(-1)
else:
  print(result)
  print(minimum)