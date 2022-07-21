minimum = 64
white_board = [['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], [
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']]
black_board = [['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], [
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'], ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'], ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']]
N, M = list(map(int, input().split()))
chess_board = []
for i in range(N):
    chess_board.append(list(input()))
for i in range(N-7):
    for j in range(M-7):
        difference_count_1 = 0
        difference_count_2 = 0
        for a in range(8):
            for b in range(8):
                if chess_board[i+a][j+b] == white_board[a][b]:
                    difference_count_1 += 1
        for a in range(8):
            for b in range(8):
                if chess_board[i+a][j+b] == black_board[a][b]:
                    difference_count_2 += 1
        if difference_count_1 < minimum:
            minimum = difference_count_1
        if difference_count_2 < minimum:
            minimum = difference_count_2
print(minimum)