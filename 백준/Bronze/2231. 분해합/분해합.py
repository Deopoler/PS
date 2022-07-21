N = int(input())
is_Exist = False
for i in range(1, N):
    if sum([int(i) for i in list(str(i))].__add__([i])) == N:
        print(i)
        is_Exist = True
        break
if (not is_Exist):
    print(0)
