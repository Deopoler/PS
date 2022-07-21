for _ in range(int(input())):
  start_x, start_y, end_x, end_y = map(int, input().split())
  count = 0
  for _ in range(int(input())):
    center_x, center_y, r = map(int, input().split())
    start_distance = ((start_x-center_x)**2 + (start_y-center_y)**2)**(0.5)
    end_distance = ((end_x-center_x)**2 + (end_y-center_y)**2)**(0.5)
    if start_distance < r and end_distance > r: # 시작점이 원 내부 and 끝점이 원 외부
      count += 1
    elif start_distance > r and end_distance < r: # 시작점이 원 외부 and 끝점이 원 내부
      count += 1
  print(count)