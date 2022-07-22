K = int(input())

direction = []
length = []
for _ in range(6):
    d, l = map(int, input().split())
    direction.append(d - 1)
    length.append(l)

h = 0
w = 0
for d, l in zip(direction, length):
    if d in (0, 1):
        h = max(h, l)
    else:
        w = max(w, l)
bigger_size = h * w

smaller_size = 1
for i in range(6):
    if direction[i] == direction[(i + 2) % 6]:
        smaller_size *= length[(i + 1) % 6]

print((bigger_size - smaller_size) * K)

