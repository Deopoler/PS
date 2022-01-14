T = int(input())

d_zeros = [1,0] + [-1] * 39
d_ones = [0,1] + [-1] * 39
N_list = []
for _ in range(T):
  N_list.append(int(input()))
for i in range(2, max(N_list)+1):
  d_zeros[i] = d_zeros[i-1] + d_zeros[i-2]
  d_ones[i] = d_ones[i-1] + d_ones[i-2]

for n in N_list:
  print(d_zeros[n], d_ones[n])