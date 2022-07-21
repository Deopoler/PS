N = input()
count = [0] * 10
for i in N:
    count[int(i)] += 1
for i in range(9,-1,-1):
    while count[i] > 0:
        print(i,end='')
        count[i] -= 1