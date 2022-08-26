N = int(input())
f = [0] * (N + 1)

for i in range(1, N + 1):
    a = int(input())
    f[i] = a

current = 1
visited = set()
count = 0
while True:
    count += 1
    current = f[current]
    if current == 2:
        break
    elif current in visited:
        break
    visited.add(current)

if current == 2:
    print(count)
else:
    print(-1)
