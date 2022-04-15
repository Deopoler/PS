import sys
input = sys.stdin.readline

sequence = []
for _ in range(int(input())):
  sequence.append(int(input()))

stack = []
currenct_num = 1
operations = []
possible = True
for i in sequence:
  while currenct_num <= i:
    stack.append(currenct_num)
    currenct_num += 1
    operations.append('+')
  if stack[-1] == i:
    stack.pop()
    operations.append('-')
  else:
    possible = False
    break
if possible:
  for oper in operations:
    print(oper)
else:
  print("NO")