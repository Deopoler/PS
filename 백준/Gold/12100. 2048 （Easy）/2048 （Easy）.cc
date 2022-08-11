#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;

vvi up(const vvi &board)
{
    int n = board.size();
    vvi temp_board(n, vi(n));
    vi nums(n);    // 같은 열 위에 있는 숫자
    vi pos(n, -1); // 같은 열 위에 있는 숫자의 움직인 후 위치(행)

    for (int i = 0; i < n; i++) // 행
    {
        for (int j = 0; j < n; j++) // 열
        {
            if (board[i][j] != 0)
            {
                if (nums[j] == 0) // 위에 숫자가 없었음 or 합친 후
                {
                    pos[j]++;              // 다음 행 선택
                    nums[j] = board[i][j]; // 위 숫자를 현재 숫자로 변경
                }
                else if (nums[j] == board[i][j]) // 위와 같은 숫자
                {
                    temp_board[pos[j]][j] = board[i][j] * 2; // 합침
                    nums[j] = 0;                             // 위 숫자 초기화
                }
                else // 위와 다른 숫자
                {
                    temp_board[pos[j]][j] = nums[j]; // 위 숫자를 올림
                    pos[j]++;                        // 다음 행 선택
                    nums[j] = board[i][j];           // 위 숫자를 현재 숫자로 변경
                }
            }

            if (i == n - 1 && nums[j] != 0) // 마지막 행이면 그냥 넣기
                temp_board[pos[j]][j] = nums[j];
        }
    }
    return temp_board;
}

vvi down(const vvi &board)
{
    int n = board.size();
    vvi temp_board(n, vi(n));
    vi nums(n);   // 같은 열 아래에 있는 숫자
    vi pos(n, n); // 같은 열 아래에 있는 숫자의 움직인 후 위치(행)

    for (int i = n - 1; i >= 0; i--) // 행 (아래부터 처리)
    {
        for (int j = 0; j < n; j++) // 열
        {
            if (board[i][j] != 0)
            {

                if (nums[j] == 0) // 아래에 숫자가 없었음 or 합친 후
                {
                    pos[j]--;              // 다음 행 선택
                    nums[j] = board[i][j]; // 아래 숫자를 현재 숫자로 변경
                }
                else if (nums[j] == board[i][j]) // 아래와 같은 숫자
                {
                    temp_board[pos[j]][j] = board[i][j] * 2; // 합침
                    nums[j] = 0;                             // 아래 숫자 초기화
                }
                else // 아래와 다른 숫자
                {
                    temp_board[pos[j]][j] = nums[j]; // 아래 숫자를 내림
                    pos[j]--;                        // 다음 행 선택
                    nums[j] = board[i][j];           // 아래 숫자를 현재 숫자로 변경
                }
            }

            if (i == 0 && nums[j] != 0) // 마지막 행이면 그냥 넣기
                temp_board[pos[j]][j] = nums[j];
        }
    }
    return temp_board;
}

vvi left(const vvi &board)
{
    int n = board.size();
    vvi temp_board(n, vi(n));
    vi nums(n);    // 같은 행 왼쪽에 있는 숫자
    vi pos(n, -1); // 같은 행 왼쪽에 있는 숫자의 움직인 후 위치(열)

    for (int i = 0; i < n; i++) // 행
    {
        for (int j = 0; j < n; j++) // 열
        {
            if (board[i][j] != 0)
            {
                if (nums[i] == 0) // 왼쪽에 숫자가 없었음 or 합친 후
                {
                    pos[i]++;              // 다음 열 선택
                    nums[i] = board[i][j]; // 왼쪽 숫자를 현재 숫자로 변경
                }
                else if (nums[i] == board[i][j]) // 왼쪽와 같은 숫자
                {
                    temp_board[i][pos[i]] = board[i][j] * 2; // 합침
                    nums[i] = 0;                             // 왼쪽 숫자 초기화
                }
                else // 왼쪽과 다른 숫자
                {
                    temp_board[i][pos[i]] = nums[i]; // 왼쪽 숫자를 보냄
                    pos[i]++;                        // 다음 열 선택
                    nums[i] = board[i][j];           // 왼쪽 숫자를 현재 숫자로 변경
                }
            }

            if (j == n - 1 && nums[i] != 0) // 마지막 열이면 그냥 넣기
                temp_board[i][pos[i]] = nums[i];
        }
    }
    return temp_board;
}

vvi right(const vvi &board)
{
    int n = board.size();
    vvi temp_board(n, vi(n));
    vi nums(n);   // 같은 행 오른쪽에 있는 숫자
    vi pos(n, n); // 같은 행 오른쪽에 있는 숫자의 움직인 후 위치(열)

    for (int i = 0; i < n; i++) // 행
    {
        for (int j = n - 1; j >= 0; j--) // 열
        {
            if (board[i][j] != 0)
            {
                if (nums[i] == 0) // 오른쪽에 숫자가 없었음 or 합친 후
                {
                    pos[i]--;              // 다음 열 선택
                    nums[i] = board[i][j]; // 오른쪽 숫자를 현재 숫자로 변경
                }
                else if (nums[i] == board[i][j]) // 오른쪽와 같은 숫자
                {
                    temp_board[i][pos[i]] = board[i][j] * 2; // 합침
                    nums[i] = 0;                             // 오른쪽 숫자 초기화
                }
                else // 오른쪽과 다른 숫자
                {
                    temp_board[i][pos[i]] = nums[i]; // 왼쪽 숫자를 보냄
                    pos[i]--;                        // 다음 열 선택
                    nums[i] = board[i][j];           // 왼쪽 숫자를 현재 숫자로 변경
                }
            }

            if (j == 0 && nums[i] != 0) // 마지막 열이면 그냥 넣기
                temp_board[i][pos[i]] = nums[i];
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

int solve(int n, const vvi &board, int turn)
{
    if (n == turn)
    {
        return max2d(board);
    }

    int ret = 0;
    ret = max(ret, solve(n, up(board), turn + 1));
    ret = max(ret, solve(n, down(board), turn + 1));
    ret = max(ret, solve(n, left(board), turn + 1));
    ret = max(ret, solve(n, right(board), turn + 1));

    return ret;
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

    cout << solve(5, board, 0) << "\n";

    return 0;
}