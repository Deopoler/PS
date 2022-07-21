N = int(input())

count = 0
add = 0
a = 1
while N > a:
    a += add
    add += 6
    count += 1
if N == 1:
    print(1)
else:
    print(count)
