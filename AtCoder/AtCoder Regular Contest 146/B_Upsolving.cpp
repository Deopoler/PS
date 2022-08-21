#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int bit = 31;
    ll result = 0;

    vector<ll> need(N, 0);
    while (bit >= 0)
    {
        vector<ll> temp_need(N);
        for (int i = 0; i < N; i++)
        {
            temp_need[i] = need[i];
            if (A[i] < (1LL << bit))
            {
                temp_need[i] += (1LL << bit) - A[i];
            }
        }

        vector<ll> sorted_temp_need(temp_need);
        sort(sorted_temp_need.begin(), sorted_temp_need.end());

        ll sum = 0;
        for (int i = 0; i < K; i++)
        {
            sum += sorted_temp_need[i];
        }

        if (sum <= M)
        {
            result += (1LL << bit);
            for (int i = 0; i < N; i++)
            {
                if (A[i] < (1LL << bit))
                {
                    A[i] += (1LL << bit) - A[i];
                }
            }
            for (int i = 0; i < N; i++)
            {
                need[i] = temp_need[i];
            }
        }

        for (int i = 0; i < N; i++)
        {
            A[i] &= (1LL << bit) - 1;
        }

        bit--;
    }

    cout << result << "\n";

    return 0;
}