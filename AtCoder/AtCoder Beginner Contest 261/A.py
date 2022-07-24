l1, r1, l2, r2 = map(int, input().split())

f = set(range(l1, r1 + 1))
s = set(range(l2, r2 + 1))

a = len(f.intersection(s))
if a > 0:
    print(a-1)
else:
    print(0)

