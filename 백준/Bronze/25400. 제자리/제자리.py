from itertools import count


n = int(input())
a = list(map(int, input().split()))

current = 1
result = 0
for i in range(len(a)):
    if a[i] == current:
        current += 1
    else:
        result += 1

print(result)
