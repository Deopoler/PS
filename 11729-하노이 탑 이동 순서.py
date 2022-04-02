K = int(input())

def hanoi(from_, to, n):
  # n번 원반을 from_에서 to로 이동하는 함수
  if n == 1:
    print(from_, to)
    return
  empty = 6 - from_ - to # 빈 곳 찾기
  hanoi(from_, empty, n-1)
  print(from_, to)
  hanoi(empty, to, n-1)

print(2**K-1)
hanoi(1,3,K)