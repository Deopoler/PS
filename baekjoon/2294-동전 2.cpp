#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> dp(10001, 10001);
    vector<int> coins;

    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    for (int i = 1; i <= k; i++)
    {
        for (auto &coin : coins)
        {

            if (i - coin >= 0)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    if (dp[k] != 10001)
    {
        cout << dp[k] << "\n";
    }
    else
    {
        cout << "-1\n";
    }

    return 0;
}