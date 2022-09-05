import itertools

S = input()

if S[0] == "1":
    print("No")

else:
    columns = [0] * 7
    if S[6] == "1":
        columns[0] = 1
    else:
        columns[0] = -1

    if S[3] == "1":
        columns[1] = 1
    else:
        columns[1] = -1

    if S[1] == "1" or S[7] == "1":
        columns[2] = 1
    elif S[1] == "0" and S[7] == "0":
        columns[2] = -1
    else:
        columns[2] = 0

    if S[0] == "1" or S[4] == "1":
        columns[3] = 1
    elif S[0] == "0" and S[4] == "0":
        columns[3] = -1
    else:
        columns[3] = 0

    if S[2] == "1" or S[8] == "1":
        columns[4] = 1
    elif S[2] == "0" and S[8] == "0":
        columns[4] = -1
    else:
        columns[4] = 0

    if S[5] == "1":
        columns[5] = 1
    else:
        columns[5] = -1

    if S[9] == "1":
        columns[6] = 1
    else:
        columns[6] = -1

    result = False
    for a, b in itertools.combinations(range(0, 7), 2):
        if columns[a] != 1 or columns[b] != 1:
            continue
        for i in range(a + 1, b):
            if columns[i] == -1:
                result = True
                break

        if result:
            break

    if result:
        print("Yes")
    else:
        print("No")
