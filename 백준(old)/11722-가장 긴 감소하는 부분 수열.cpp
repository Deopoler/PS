#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<int> dp(N, 1);
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < i; k++)
        {
            if (A[k] > A[i])
            {
                dp[i] = max(dp[i], dp[k] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";

    return 0;
}