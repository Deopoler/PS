#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000000;

void solve()
{
    int N;
    cin >> N;

    int K;
    cin >> K;

    int dp[K + 1][N + 1] = {}; // dp[i][j] = 숫자 i개를 사용하여 j를 만들 수 있는 경우의 수

    for (int i = 0; i <= N; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= K; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[K][N] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}