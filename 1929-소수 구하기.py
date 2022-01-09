M,N = map(int, input().split())


sieve = [True] * (N+1)

a = int(N ** 0.5)
for i in range(2, a + 1):
    if sieve[i] == True: 
        for j in range(i+i, N+1, i): 
            sieve[j] = False
        

for i in range(2,N+1):
  if sieve[i] and i >= M:
    print(i)