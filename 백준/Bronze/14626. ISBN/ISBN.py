isbn = input()

weight = 0
n = 0
current = 1
for i in isbn:
    if i == '*':
        weight = current
    else:
        n += int(i)*current

    if current == 1:
        current = 3
    else:
        current = 1

for i in range(10):
    if ((i*weight+n) % 10) == 0:
        print(i)
        break