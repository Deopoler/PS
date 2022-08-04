#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    long long sum[N];
    long long count[M] = {0};
    sum[0] = A[0] % M;
    count[sum[0]]++;
    for (int i = 1; i < N; i++)
    {
        sum[i] = (sum[i - 1] + A[i]) % M;
        count[sum[i]]++;
    }

    long long result = count[0];
    for (int i = 0; i < M; i++)
    {
        if (count[i] >= 2)
            result += count[i] * (count[i] - 1) / 2;
    }

    cout << result << "\n";

    return 0;
}