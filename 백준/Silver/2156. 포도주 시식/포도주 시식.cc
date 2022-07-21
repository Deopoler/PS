#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> dp(N, 0);
    vector<int> in(N);
    for (int i = 0; i < N; i++)
    {
        cin >> in[i];
    }

    if (N == 1)
    {
        cout << in[0] << "\n";
    }
    else if (N == 2)
    {
        cout << in[0] + in[1] << "\n";
    }
    else if (N == 3)
    {
        cout << max({in[0] + in[1], in[0] + in[2], in[1] + in[2]}) << "\n";
    }
    else
    {
        dp[0] = in[0];
        dp[1] = in[0] + in[1];
        dp[2] = max({in[0] + in[1], in[0] + in[2], in[1] + in[2]});
        for (int i = 3; i < N; i++)
        {
            dp[i] = max({dp[i - 2] + in[i], dp[i - 3] + in[i - 1] + in[i], dp[i - 1]});
        }

        cout << dp[N - 1] << "\n";
    }

    return 0;
}