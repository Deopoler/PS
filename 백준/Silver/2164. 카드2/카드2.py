from collections import deque

nums = deque([i for i in range(1, int(input())+1)])
while len(nums) > 1:
    nums.popleft()
    nums.append(nums[0])
    nums.popleft()
print(nums[0])
