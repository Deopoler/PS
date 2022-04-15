import sys

small = 0 # 소괄호
large = 1 # 대괄호

for line in sys.stdin:
  line = line.rstrip()
  if line == '.':
    break
  brackets = []
  balanced = True
  for char in line:
    if char == '(':
      brackets.append(small)
    elif char == ')':
      if not brackets:
        balanced = False
        break
      prior_bracket = brackets.pop()
      if prior_bracket != small:
        balanced = False
        break
    if char == '[':
      brackets.append(large)
    elif char == ']':
      if not brackets:
        balanced = False
        break
      prior_bracket = brackets.pop()
      if prior_bracket != large:
        balanced = False
        break
  if balanced and not brackets:
    print('yes')
  else:
    print('no')