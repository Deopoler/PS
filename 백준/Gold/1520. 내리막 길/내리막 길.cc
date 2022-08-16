#include <bits/stdc++.h>

#define MAX 500

using namespace std;

int cache[MAX][MAX];

int drow[4] = {0, 0, 1, -1};
int dcol[4] = {1, -1, 0, 0};

int arr[MAX][MAX];
int M, N;

int solve(int row, int col)
{
    if (cache[row][col] != -1)
        return cache[row][col];

    int &ret = cache[row][col];

    if (row == M - 1 && col == N - 1)
        return ret = 1;
    ret = 0; // 최솟값은 0
    for (int i = 0; i < 4; i++)
    {
        int next_row = row + drow[i];
        int next_col = col + dcol[i];
        if (next_row < 0 || next_row >= M || next_col < 0 || next_col >= N || arr[row][col] <= arr[next_row][next_col])
            continue;

        ret += solve(next_row, next_col);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(cache, -1, sizeof(cache));
    cin >> M >> N;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << solve(0, 0) << "\n";
    return 0;
}