n = int(input())

strings = {}
for _ in range(n):
    d = input()
    if d not in strings:
        strings[d] = 1
        print(d)
    else:
        print(f"{d}({strings[d]})")
        strings[d] += 1
