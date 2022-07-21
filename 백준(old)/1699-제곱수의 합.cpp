#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> dp(N + 1);

    for (int i = 1; i <= N; i++)
    {
        dp[i] = i; // 최대 개수는 1만 더한 것

        for (int j = 1; pow(j, 2) <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - pow(j, 2)] + 1);
        }
    }

    cout << dp[N] << "\n";

    return 0;
}