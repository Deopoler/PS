inputV = input()
while inputV != '0':
    if (inputV == inputV[::-1]):
        print("yes")
    else:
        print("no")
    inputV = input()
