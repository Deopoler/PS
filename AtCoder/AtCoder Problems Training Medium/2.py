S = input()

result = 0
count = 0
for i in range(len(S)):
    if S[i] == "W":
        result += i - count
        count += 1

print(result)
