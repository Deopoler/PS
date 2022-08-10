#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int nums[N - 1];
    int target;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> nums[i];
    }
    cin >> target;

    ll dp[N - 1][21] = {}; // dp[i][j] = i번째까지의 숫자를 사용해서 j를 만들 수 있는 경우의 수
    dp[0][nums[0]] = 1;    // 첫번째 숫자는 예외로 처리

    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (0 <= j - nums[i] && j - nums[i] <= 20)
            {
                dp[i][j] += dp[i - 1][j - nums[i]];
            }
            if (0 <= j + nums[i] && j + nums[i] <= 20)
            {
                dp[i][j] += dp[i - 1][j + nums[i]];
            }
        }
    }

    cout << dp[N - 2][target] << "\n";

    return 0;
}