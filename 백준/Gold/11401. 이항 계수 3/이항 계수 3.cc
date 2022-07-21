#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

tuple<long long, long long, long long> extendedEuclideanAlgo(long long a, long long b)
{
    long long x_2 = 1;
    long long x_1 = 0;
    long long y_2 = 0;
    long long y_1 = 1;

    long long s_2 = a;
    long long s_1 = b;

    long long x, y, s;

    long long q, r;

    while (b != 0)
    {
        q = a / b;
        r = a % b;

        x = x_2 - x_1 * q;
        y = y_2 - y_1 * q;
        s = s_2 - s_1 * q;

        a = b;
        b = r;

        x_2 = x_1;
        x_1 = x;

        y_2 = y_1;
        y_1 = y;

        s_2 = s_1;
        s_1 = s;
    }

    return {a, x_2, y_2}; // gcd, x, y when ax + by = gcd(a,b)
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<long long> factorial(N + 1);
    factorial[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        factorial[i] = (i * factorial[i - 1]) % MOD;
    }

    long long _, __, inv;
    tie(_, __, inv) = extendedEuclideanAlgo(MOD, factorial[K] * factorial[N - K]);

    long long result = ((factorial[N] % MOD) * (inv % MOD)) % MOD;
    while (result < 0)
        result += MOD;

    cout << result << "\n";

    return 0;
}