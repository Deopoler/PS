input()
A = input().split()
A.sort(reverse=True, key=lambda x: (len(x), x))
A = A[:3]
A.sort(reverse=True)


for i in A:
    print(i, end="")
print()
