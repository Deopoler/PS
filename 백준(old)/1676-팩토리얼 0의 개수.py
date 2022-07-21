N = int(input())

count_two = 0
count_five = 0
for i in range(1, N+1):
  a = i
  while a % 2 == 0:
    a //= 2
    count_two += 1
  while a % 5 == 0:
    a //= 5
    count_five += 1

print(min(count_two, count_five))