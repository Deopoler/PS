inputs = set()
for i in range(int(input())):
    inputs.add(input())
inputs = list(inputs)
inputs.sort(key=lambda word: (len(word), word))
for word in inputs:
    print(word)
