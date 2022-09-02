n = int(input())
x = list(map(int, input().split()))

result = 501
for i in range(len(x) - 1):
    for j in range(i + 1, len(x)):
        diff = (x[j] - x[i]) / (j - i)
        first = x[i] - diff * i
        temp = 0
        for k in range(len(x)):
            if x[k] != first + diff * k:
                temp += 1

        result = min(result, temp)

print(result)
