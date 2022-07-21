#include <iostream>
#include <tuple>
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

    return make_tuple(a, x_2, y_2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        long long K, C;
        cin >> K >> C;
        if (K == 1)
        {
            cout << "2\n";
        }
        else if (C == 1)
        {
            if (K + 1 > 1000000000)
            {
                cout << "IMPOSSIBLE\n";
            }
            else
            {
                cout << K + 1 << "\n";
            }
        }
        else
        {
            long long gcd, x, y;

            tie(gcd, x, y) = extendedEuclideanAlgo(K, C);

            if (gcd != 1)
            {
                cout << "IMPOSSIBLE\n";
            }
            else
            {
                while (y > K)
                {
                    y -= K;
                }
                while (y < 0)
                {
                    y += K;
                }
                if (y > 1000000000)
                {
                    cout << "IMPOSSIBLE\n";
                }
                else
                {
                    cout << y << "\n";
                }
            }
        }
    }
}