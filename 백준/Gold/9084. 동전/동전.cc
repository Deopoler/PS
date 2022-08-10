#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int N;
    cin >> N;

    int coins[N];
    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }

    int M;
    cin >> M;

    int dp[M + 1] = {};
    for (auto &&coin : coins)
    {
        if (coin > M)
        {
            continue;
        }
        dp[coin] += 1;
        for (int i = coin + 1; i <= M; i++)
        {
            dp[i] += dp[i - coin];
        }
    }

    cout << dp[M] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve();
    }

    return 0;
}