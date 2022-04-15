import sys
input=sys.stdin.readline
N,M=input().split()
a=0
d=[]
for i in input().split():
  a+=int(i)
  d.append(a)
for _ in range(int(M)):
  i,j=map(int,input().split())
  print(d[j-1]-d[i-2]if i>1else d[j-1])