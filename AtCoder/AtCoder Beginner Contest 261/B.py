N = int(input())
A  = []
for i in range(N):
    A.append(input())


correct= True
for i in range(N):
    for j in range(N):
        if i == j and A[i][j] != '-':
            correct = False
            break
        if A[i][j] == "W" and A[j][i] != "L":
            correct = False
            break
        if A[i][j] == "L" and A[j][i] != "W":
            correct = False
            break
        if A[i][j] == "D" and A[j][i] != "D":
            correct = False
            break

if correct:
    print("correct")
else:
    print("incorrect")