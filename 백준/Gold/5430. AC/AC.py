from collections import deque

for i in range(int(input())):
    direction = True  # True: left, False: right
    func = input()
    input()
    x = deque(eval(input()))
    error_occured = False
    for f in func:
        if f == "R":
            direction = not direction
        elif f == "D":
            if not x:
                error_occured = True
                break
            if direction:
                x.popleft()
            else:
                x.pop()

    if not error_occured:
        if not x:
            print("[]")
        else:
            print("[", end="")
            while len(x) > 1:
                if direction:
                    print(x.popleft(), end=",")
                else:
                    print(x.pop(), end=",")
            if direction:
                print(x.popleft(), end="]\n")
            else:
                print(x.pop(), end="]\n")
    else:
        print("error")
