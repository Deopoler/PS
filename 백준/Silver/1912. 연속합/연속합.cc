#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(100001, -1001);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        dp[i] = max(x, dp[i - 1] + x);
    }
    cout << *max_element(dp.begin() + 1, dp.begin() + n + 1);

    return 0;
}