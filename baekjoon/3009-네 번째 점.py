x_list = []
y_list = []

for _ in range(3):
  x,y = map(int, input().split())
  x_list.append(x)
  y_list.append(y)

result_x = -1
for i in range(3):
  for j in range(i+1, 3):
    if x_list[i] == x_list[j]:
      for idx in [0,1,2]:
        if idx != i and idx != j:
          result_x = x_list[idx]
          
result_y = -1
for i in range(3):
  for j in range(i+1, 3):
    if y_list[i] == y_list[j]:
      for idx in [0,1,2]:
        if idx != i and idx != j:
          
          result_y = y_list[idx]

print(result_x, result_y)