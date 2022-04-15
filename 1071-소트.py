def check(a, nums, not_result):
  added_list = nums + not_result + [a]
  if not added_list:
    return True
  min_value = 1001
  max_value = -1
  for num in added_list:
    if num > max_value:
      max_value = num
    if num < min_value:
      min_value = num
  if (a == min_value and a + 1 == max_value):
    return False
  return True


N = int(input())
nums = sorted(map(int, input().split()), reverse=True)
result = []
prior_num = -2
not_result = []
while nums:
  a = nums.pop()
  if a != prior_num + 1 and check(a,nums, not_result):
    prior_num = a
    result.append(a)
    nums += not_result[::-1]
    not_result = []
  else:
    not_result.append(a)
print(*result)