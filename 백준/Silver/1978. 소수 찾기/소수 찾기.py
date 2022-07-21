input()
numbers = list(map(int, input().split()))
prime_numbers = [i for i in range(2, max(numbers)+1)]
for i in prime_numbers:
    for j in prime_numbers:
        if (j % i == 0 and j != i):
            prime_numbers.remove(j)
count = 0
for i in numbers:
    if i in prime_numbers:
        count += 1
print(count)
