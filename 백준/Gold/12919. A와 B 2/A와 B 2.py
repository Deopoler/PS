S = input()
T = input()

def solve(target):
  if len(S) == len(target):
    return S == target

  if target[-1] == 'A' and solve(target[:-1]):
    return True

  if target[0] == 'B' and solve(target[::-1][:-1]):
    return True

  return False

if solve(T):
  print(1)
else:
  print(0)