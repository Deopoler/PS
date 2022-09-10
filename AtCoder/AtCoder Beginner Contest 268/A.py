li = list(map(int, input().split()))

li.sort()

count = 0
for i in range(4):
    if li[i] != li[i + 1]:
        count += 1

print(count + 1)
