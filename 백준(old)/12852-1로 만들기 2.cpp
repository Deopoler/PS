#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> dp(N + 1, N + 1); // 방식 최솟값
    vector<int> path(N + 1, -1);  // 이전 위치

    dp[N] = 0;
    for (int i = N - 1; i > 0; i--)
    {
        int count;
        if (i * 2 <= N)
        {
            count = dp[i * 2] + 1;
            if (count < dp[i])
            {
                dp[i] = count;
                path[i] = i * 2;
            }
        }
        if (i * 3 <= N)
        {
            count = dp[i * 3] + 1;
            if (count < dp[i])
            {
                dp[i] = count;
                path[i] = i * 3;
            }
        }
        count = dp[i + 1] + 1;
        if (count < dp[i])
        {
            dp[i] = count;
            path[i] = i + 1;
        }
    }

    cout << dp[1] << "\n";

    vector<int> result;
    int temp = 1;
    while (temp != N)
    {
        result.push_back(path[temp]);
        temp = path[temp];
    }

    for (auto i = result.rbegin(); i != result.rend(); ++i)
    {
        cout << *i << " ";
    }

    cout << "1\n";
    return 0;
}