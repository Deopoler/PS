li = list(map(int, input().split()))
li.sort()

if (li[0] == li[1] and li[2] == li[4]) or (li[0] == li[2] and li[3] == li[4]):
    print("Yes")
else:
    print("No")