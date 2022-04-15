# -----------
#  50점 코드
# -----------
# N = int(input())
# input()
# P = "I"+ "OI"*N
# def countoverlapped(string, substring):
#   count = 0
#   start = 0
#   while start < len(string):
#       pos = string.find(substring, start)
#       if pos != -1:
#           start = pos + 1
#           count += 1
#       else:
#           break
#   return count
# print(countoverlapped(input(), P))

# -----------
#  100점 코드
# -----------
N = int(input())
M = int(input())
P = "I"+"OI"*N
S = input()

pattern = 0
result = 0
i = 0
while i < M-2:
  if S[i] == 'I' and S[i+1] == 'O' and S[i+2] == 'I':
    pattern += 1
    i+=1
  else:
    pattern = 0
  if pattern >= N:
    result += 1
  i+=1
print(result)