N = int(input())
count = 0
if (N >= 99):
    count += 99
    for i in range(100, N+1):
        h = i//100
        t = (i % 100)//10
        o = i % 10
        if h-t == t-o:
            count += 1
else:
    count += N
print(count)
