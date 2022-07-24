#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, Q;
    string S;

    cin >> N >> Q;
    cin >> S;

    int pos = 0;

    for (int i = 0; i < Q; i++)
    {
        int a, x;
        cin >> a >> x;
        if (a == 1)
        {
            pos = ((pos - x) + N) % N;
        }
        else
        {
            cout << S[(pos + x - 1) % N] << "\n";
        }
    }

    return 0;
}