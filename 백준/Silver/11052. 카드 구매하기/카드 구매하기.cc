#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> card(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> card[i];
    }

    vector dp(N + 1, 0);
    for (int i = N; i > 0; i--)
    {
        for (int j = i; j <= N; j++)
        {
            dp[j] = max(dp[j], dp[j - i] + card[i]);
        }
    }

    cout << dp[N] << "\n";

    return 0;
}