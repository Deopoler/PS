N = int(input())

count = {-1:0,0:0,1:0}

def split(paper,x_start,y_start,n):
  global count
  first = paper[y_start][x_start]
  for i in range(n):
    for j in range(n):
      if paper[y_start+i][x_start+j] != first:
        split(paper, x_start, y_start, n//3) #왼쪽 위
        split(paper, x_start, y_start+n//3, n//3) #왼쪽 중간
        split(paper, x_start, y_start+2*(n//3), n//3) #왼쪽 아래
      
        split(paper, x_start+n//3, y_start, n//3) #가운데 위
        split(paper, x_start+n//3, y_start+n//3, n//3) #가운데 중간
        split(paper, x_start+n//3, y_start+2*(n//3), n//3) #가운데 아래
      
        split(paper, x_start+2*(n//3), y_start, n//3) #오른쪽 위
        split(paper, x_start+2*(n//3), y_start+n//3, n//3) #오른쪽 중간
        split(paper, x_start+2*(n//3), y_start+2*(n//3), n//3) #오른쪽 아래
        return

  count[first] += 1
  

paper = []
for _ in range(N):
  paper.append(list(map(int, input().split())))

split(paper, 0,0, N)

print(count[-1])
print(count[0])
print(count[1])