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
    vector<int> track(N, -1);
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < i; k++)
        {
            if (A[k] < A[i])
            {
                if (dp[i] < dp[k] + 1)
                {
                    dp[i] = dp[k] + 1;
                    track[i] = k;
                }
            }
        }
    }

    auto max_iter = max_element(dp.begin(), dp.end());
    cout << *max_iter << "\n";

    vector<int> result_list;
    int temp = max_iter - dp.begin();
    while (track[temp] != -1)
    {
        result_list.push_back(A[temp]);
        temp = track[temp];
    }
    result_list.push_back(A[temp]);

    for (auto i = result_list.rbegin(); i != result_list.rend(); i++)
    {
        cout << *i << " ";
    }

    return 0;
}