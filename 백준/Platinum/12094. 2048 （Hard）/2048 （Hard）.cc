#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;

vvi up(const vvi &board)
{
    int n = board.size();
    vvi temp_board(n, vi(n));

    for (int j = 0; j < n; j++) // 열
    {
        int num = 0;                // 같은 열 아래에 있는 숫자
        int pos = -1;               // 같은 열 아래에 있는 숫자의 움직인 후 위치(행)
        for (int i = 0; i < n; i++) // 행
        {
            if (board[i][j] != 0)
            {
                if (num == 0) // 위에 숫자가 없었음 or 합친 후
                {
                    pos++;             // 다음 행 선택
                    num = board[i][j]; // 위 숫자를 현재 숫자로 변경
                }
                else if (num == board[i][j]) // 위와 같은 숫자
                {
                    temp_board[pos][j] = board[i][j] * 2; // 합침
                    num = 0;                              // 위 숫자 초기화
                }
                else // 위와 다른 숫자
                {
                    temp_board[pos][j] = num; // 위 숫자를 올림
                    pos++;                    // 다음 행 선택
                    num = board[i][j];        // 위 숫자를 현재 숫자로 변경
                }
            }

            if (i == n - 1 && num != 0) // 마지막 행이면 그냥 넣기
                temp_board[pos][j] = num;
        }
    }
    return temp_board;
}

vvi down(const vvi &board)
{
    int n = board.size();
    vvi temp_board(n, vi(n));

    for (int j = 0; j < n; j++) // 열
    {
        int num = 0;                     // 같은 열 아래에 있는 숫자
        int pos = n;                     // 같은 열 아래에 있는 숫자의 움직인 후 위치(행)
        for (int i = n - 1; i >= 0; i--) // 행 (아래부터 처리)
        {
            if (board[i][j] != 0)
            {

                if (num == 0) // 아래에 숫자가 없었음 or 합친 후
                {
                    pos--;             // 다음 행 선택
                    num = board[i][j]; // 아래 숫자를 현재 숫자로 변경
                }
                else if (num == board[i][j]) // 아래와 같은 숫자
                {
                    temp_board[pos][j] = board[i][j] * 2; // 합침
                    num = 0;                              // 아래 숫자 초기화
                }
                else // 아래와 다른 숫자
                {
                    temp_board[pos][j] = num; // 아래 숫자를 내림
                    pos--;                    // 다음 행 선택
                    num = board[i][j];        // 아래 숫자를 현재 숫자로 변경
                }
            }

            if (i == 0 && num != 0) // 마지막 행이면 그냥 넣기
                temp_board[pos][j] = num;
        }
    }
    return temp_board;
}

vvi left(const vvi &board)
{
    int n = board.size();
    vvi temp_board(n, vi(n));

    for (int i = 0; i < n; i++) // 행
    {
        int num = 0;                // 같은 행 왼쪽에 있는 숫자
        int pos = -1;               // 같은 행 왼쪽에 있는 숫자의 움직인 후 위치(열)
        for (int j = 0; j < n; j++) // 열
        {
            if (board[i][j] != 0)
            {
                if (num == 0) // 왼쪽에 숫자가 없었음 or 합친 후
                {
                    pos++;             // 다음 열 선택
                    num = board[i][j]; // 왼쪽 숫자를 현재 숫자로 변경
                }
                else if (num == board[i][j]) // 왼쪽와 같은 숫자
                {
                    temp_board[i][pos] = board[i][j] * 2; // 합침
                    num = 0;                              // 왼쪽 숫자 초기화
                }
                else // 왼쪽과 다른 숫자
                {
                    temp_board[i][pos] = num; // 왼쪽 숫자를 보냄
                    pos++;                    // 다음 열 선택
                    num = board[i][j];        // 왼쪽 숫자를 현재 숫자로 변경
                }
            }

            if (j == n - 1 && num != 0) // 마지막 열이면 그냥 넣기
                temp_board[i][pos] = num;
        }
    }
    return temp_board;
}

vvi right(const vvi &board)
{
    int n = board.size();
    vvi temp_board(n, vi(n));

    for (int i = 0; i < n; i++) // 행
    {
        int num = 0;                     // 같은 행 오른쪽에 있는 숫자
        int pos = n;                     // 같은 행 오른쪽에 있는 숫자의 움직인 후 위치(열)
        for (int j = n - 1; j >= 0; j--) // 열
        {
            if (board[i][j] != 0)
            {
                if (num == 0) // 오른쪽에 숫자가 없었음 or 합친 후
                {
                    pos--;             // 다음 열 선택
                    num = board[i][j]; // 오른쪽 숫자를 현재 숫자로 변경
                }
                else if (num == board[i][j]) // 오른쪽와 같은 숫자
                {
                    temp_board[i][pos] = board[i][j] * 2; // 합침
                    num = 0;                              // 오른쪽 숫자 초기화
                }
                else // 오른쪽과 다른 숫자
                {
                    temp_board[i][pos] = num; // 왼쪽 숫자를 보냄
                    pos--;                    // 다음 열 선택
                    num = board[i][j];        // 왼쪽 숫자를 현재 숫자로 변경
                }
            }

            if (j == 0 && num != 0) // 마지막 열이면 그냥 넣기
                temp_board[i][pos] = num;
        }
    }
    return temp_board;
}

int max2d(const vvi &board)
{
    int ret = 0;
    for (auto &i : board)
    {
        ret = max(ret, *max_element(i.begin(), i.end()));
    }
    return ret;
}

int result = 0;

void solve(int n, const vvi &board, int turn)
{
    int current_max = max2d(board);
    result = max(result, current_max);
    if (current_max <= result / (1 << (n - turn)))
    {
        return;
    }
    if (n == turn)
    {
        return;
    }

    vvi temp;
    temp = up(board);
    if (temp != board)
    {
        solve(n, temp, turn + 1);
    }
    temp = down(board);
    if (temp != board)
    {
        solve(n, temp, turn + 1);
    }
    temp = left(board);
    if (temp != board)
    {
        solve(n, temp, turn + 1);
    }
    temp = right(board);
    if (temp != board)
    {
        solve(n, temp, turn + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vvi board(N, vi(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    solve(10, board, 0);

    cout << result << "\n";

    return 0;
}