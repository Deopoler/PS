input()

total = 0
current = 0

for i in sorted(map(int, input().split())):
  current += i
  total += current
print(total)