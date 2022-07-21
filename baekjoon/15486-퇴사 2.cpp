#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> T(N + 1);
    vector<int> P(N + 1);

    vector<int> dp(N + 2, 0); // 깔끔한 코드를 위한 여유공간 + 1

    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }
    if (T[N] == 1)
    {
        dp[N] = P[N];
    }
    else
    {
        dp[N] = 0;
    }

    for (int i = N - 1; i >= 1; i--)
    {
        if (i + T[i] - 1 <= N)
        {
            dp[i] = max(dp[i + T[i]] + P[i], dp[i + 1]);
        }
        else
        {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[1] << "\n";

    return 0;
}