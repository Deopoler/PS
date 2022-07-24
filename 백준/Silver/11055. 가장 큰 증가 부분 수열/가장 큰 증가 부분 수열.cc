#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int dp[N];

    for (int i = 0; i < N; i++)
    {
        dp[i] = A[i];
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
            {
                dp[i] = max(dp[j] + A[i], dp[i]);
            }
        }
    }

    cout << *max_element(dp, dp + N);

    return 0;
}