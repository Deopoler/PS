#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    int dp[N + 1][N + 1];
    memset(dp, 0x7f, sizeof(dp));

    dp[0][1] = dp[1][0] = 0;

    int pitch[N + 1] = {};
    for (int i = 1; i <= N; i++)
    {
        cin >> pitch[i];
    }

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i == j)
                continue;
            int next = max(i, j) + 1;

            if (next > N)
                continue;

            if (i == 0 || j == 0)
            {
                pitch[0] = pitch[next];
            }

            dp[next][j] = min(dp[next][j], dp[i][j] + abs(pitch[i] - pitch[next]));
            dp[i][next] = min(dp[i][next], dp[i][j] + abs(pitch[j] - pitch[next]));
        }
    }

    int result = INT_MAX;
    for (int i = 0; i <= N; i++)
    {
        result = min(result, dp[N][i]);
        result = min(result, dp[i][N]);
    }

    cout << result << "\n";

    return 0;
}