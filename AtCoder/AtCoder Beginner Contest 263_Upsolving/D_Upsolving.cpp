#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N, L, R;
    cin >> N >> L >> R;

    ll A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    ll dp_l[N];
    dp_l[0] = min(A[0], L);
    for (int i = 1; i < N; i++)
    {
        dp_l[i] = min(dp_l[i - 1] + A[i], L * (i + 1));
    }

    ll dp_r[N];
    dp_r[N - 1] = min(A[N - 1], R);
    for (int i = 1; i < N; i++)
    {
        dp_r[N - i - 1] = min(dp_r[N - i] + A[N - i - 1], R * (i + 1));
    }

    ll result = min(dp_l[N - 1], dp_r[0]);
    for (int i = 1; i < N - 1; i++)
    {
        result = min(result, dp_l[i] + dp_r[i + 1]);
    }

    cout << result << "\n";

    return 0;
}