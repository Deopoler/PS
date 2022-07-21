#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int dp[10001] = {0};
    vector<int> coins;

    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    for (auto &coin : coins)
    {
        for (int i = 1; i <= k; i++)
        {

            if (i - coin >= 0)
            {
                dp[i] += dp[i - coin];
            }
        }
    }

    cout << dp[k] << "\n";

    return 0;
}