N = int(input())

white_count = 0
blue_count = 0

def split(paper,x_start,y_start,n):
  global white_count, blue_count
  all_white = True
  all_blue = True
  for i in range(n):
    for j in range(n):
      if paper[y_start+i][x_start+j] == 0:
        all_blue = False
      else:
        all_white = False

      if not all_blue and not all_white:
        break
    if not all_blue and not all_white:
        break

  if all_white:
    white_count += 1
    return
  if all_blue:
    blue_count += 1
    return

  split(paper, x_start, y_start, n//2) #왼쪽 위
  split(paper, x_start, y_start+n//2, n//2) #왼쪽 아래
  split(paper, x_start+n//2, y_start, n//2) #오른쪽 위
  split(paper, x_start+n//2, y_start+n//2, n//2) #오른쪽 아래

paper = []
for _ in range(N):
  paper.append(list(map(int, input().split())))

split(paper, 0,0, N)

print(white_count)
print(blue_count)