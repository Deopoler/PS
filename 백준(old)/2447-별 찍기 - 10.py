n = int(input())

stars = [[0] * n for _ in range(n)]

def make_star(x,y,n):
  if n == 3:
    for i in range(x, x+3):
      for j in range(y, y+3):
        stars[j][i] = 1
    stars[y+1][x+1] = 0

  else:
    next_n = n // 3
    make_star(x,y,next_n)
    make_star(x+next_n,y,next_n)
    make_star(x+2*next_n,y,next_n)
    make_star(x,y+next_n,next_n)
    make_star(x+2*next_n,y+next_n,next_n)
    make_star(x,y+2*next_n,next_n)
    make_star(x+next_n,y+2*next_n,next_n)
    make_star(x+2*next_n,y+2*next_n,next_n)

make_star(0,0,n)

for i in range(n):
  for j in range(n):
    if stars[j][i] == 1:
      print("*", end = "")
    else:
      print(" ", end = "")
  print()