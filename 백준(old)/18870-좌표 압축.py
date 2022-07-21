N = int(input())
nums = list(map(int, input().split()))
sorted_index = sorted(range(N), key=lambda x: nums[x])
results = [0] * N

prior_num = None
temp = -1
for i in sorted_index:
  if nums[i] == prior_num:
    results[i] = str(temp)
  else:
    prior_num = nums[i]
    temp += 1
    results[i] = str(temp)
print(' '.join(results))