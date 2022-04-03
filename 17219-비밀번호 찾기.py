import sys
input = sys.stdin.readline

N, M = map(int, input().split())

password = {}

for _ in range(N):
  site, pswd = input().split()
  password[site] = pswd

for _ in range(M):
  site = input().rstrip()
  print(password[site])