#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N;
    cin >> N;

    vector<ll> dp(N);

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < N; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    cout << dp[N - 1];

    return 0;
}