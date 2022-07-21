N = int(input())

bunmo = 1
bunja = 1
beforeislast = False
current_direction = False  # True => 분자 커지고 분모 작아짐, False => 분모 커지고 분자 작아짐
for i in range(1, N):
    if (bunja == 1):
        if (beforeislast):
            current_direction = True
            bunja += 1
            bunmo -= 1
            beforeislast = False
        else:
            beforeislast = True
            bunmo += 1
    elif (bunmo == 1):
        if (beforeislast):
            current_direction = False
            bunja -= 1
            bunmo += 1
            beforeislast = False
        else:
            beforeislast = True
            bunja += 1
    else:
        if current_direction:
            bunja += 1
            bunmo -= 1
        else:
            bunja -= 1
            bunmo += 1
print(f"{bunja}/{bunmo}")
