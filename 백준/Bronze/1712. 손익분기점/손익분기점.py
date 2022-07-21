inputV = [int(x) for x in input().split()]
if (inputV[1] >= inputV[2]):
    print(-1)
else:
    print(inputV[0] // (inputV[2] - inputV[1])+1)
