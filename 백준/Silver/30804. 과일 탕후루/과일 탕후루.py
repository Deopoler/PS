N = int(input())
fruits = list(map(int,input().split()))

result = 0
f1 = -1
f2 = -1
f1_idx = 0
f2_idx = 0
start = 0

for i,f in enumerate(fruits):
    if f1 == -1:
        f1 = f
    elif f == f1:
        f1_idx = i
    elif f == f2:
        f2_idx = i
    elif f2 == -1:
        f2 = f
        f2_idx = i
    else:
        if f1_idx < f2_idx:
            f1 = f
            start = f1_idx + 1
            f1_idx = i
        else:
            f2 = f
            start = f2_idx + 1 
            f2_idx = i              
    result = max(result, i - start +1)

print(result)