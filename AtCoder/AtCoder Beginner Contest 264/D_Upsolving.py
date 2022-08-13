S = input()

index = {a: idx for idx, a in enumerate("atcoder")}

S_idx = [index[s] for s in S]


result = 0
for i in range(6):
    for j in range(i + 1, 7):
        if S_idx[i] > S_idx[j]:
            result += 1

print(result)
