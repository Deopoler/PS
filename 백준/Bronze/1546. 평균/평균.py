input()
score_list = [int(x) for x in input().split(" ")]
max_score = max(score_list)
score_list = [x/max_score*100 for x in score_list]
print(sum(score_list)/len(score_list))