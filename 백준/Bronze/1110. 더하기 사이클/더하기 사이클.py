import sys

temp = 0


def getResult(input):
    global temp
    present_0 = list(input)[0]
    present_1 = "0"
    if (len(list(input)) > 1):
        present_1 = list(input)[1]
    present_lst = list(str(int(present_0) + int(present_1)))
    if (len(present_lst) > 1):
        present_num = present_lst[1]
    else:
        present_num = present_lst[0]
    temp += 1
    if (len(list(input)) > 1):
        return(present_1 + present_num)
    else:
        return(present_0 + present_num)


inputV = sys.stdin.readline().rstrip()
result = getResult(inputV)
while True:
    if (int(result) == int(inputV)):
        break
    result = getResult(result)
print(temp)
