stack = []
answer = ""

for s in input():
    if s.isalpha():
        answer += s

    elif s == "(":
        stack.append(s)

    elif s == ")":
        while stack and stack[-1] != "(":
            answer += stack.pop()
        stack.pop()

    elif s in "*/":
        while stack and stack[-1] in "*/" and stack[-1] != "(":
            answer += stack.pop()
        stack.append(s)

    elif s in "+-":
        while stack and stack[-1] != "(":
            answer += stack.pop()
        stack.append(s)

while stack:
    answer += stack.pop()

print(answer)
