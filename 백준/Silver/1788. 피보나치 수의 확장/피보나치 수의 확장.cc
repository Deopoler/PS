#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    if (N == 0)
    {
        cout << "0\n0\n";
        return 0;
    }

    vector<int> fibonacci(abs(N) + 1, 0);

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i <= abs(N); i++)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        fibonacci[i] %= MOD;
    }

    if (N < 0)
    {
        if (N % 2 == 0)
        {
            cout << "-1";
        }
        else
        {
            cout << "1";
        }
    }
    else
    {
        cout << "1";
    }
    cout << "\n";

    cout << abs(fibonacci[abs(N)]) << "\n";

    return 0;
}