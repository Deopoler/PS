S = input()
S = S.upper()
counter = [0] * 26
for i in range(65, 91):
    counter[i-65] = S.count(chr(i))
if (counter.count(max(counter)) < 2):
    print(chr(counter.index(max(counter))+65))
else:
    print("?")
