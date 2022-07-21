N = int(input())
group_word = 0
for _ in range(N):
    ended_char = []
    before_char = ""
    is_group_word = True
    word = input()
    for i in range(len(word)):
        if before_char != "":
            if before_char != word[i]:
                if word[i] in ended_char:
                    is_group_word = False
                ended_char.append(word[i-1])
                before_char = word[i]
        else:
            before_char = word[i]
    if is_group_word:
        group_word += 1

print(group_word)
