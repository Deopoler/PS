N = int(input())
P = [-1, -1] + list(map(int, input().split()))

i = N
count = 0
while i != 1:
    i = P[i]
    count += 1

print(count)
