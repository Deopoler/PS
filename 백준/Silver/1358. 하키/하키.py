def distance(x, y, a, b):
    return ((x - a) ** 2 + (y - b) ** 2) ** 0.5


W, H, X, Y, P = map(int, input().split())
R = H / 2
result = 0
for _ in range(P):
    x, y = map(int, input().split())
    if X <= x <= X + W and Y <= y <= Y + H:
        result += 1
    elif distance(x, y, X, Y + R) <= R or distance(x, y, X + W, Y + R) <= R:
        result += 1

print(result)
