#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll sum = 0;
    int xor_ = 0;
    int query;
    int x;
    multiset<int> A;
    A.insert(0);

    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> query;
        switch (query)
        {
        case 1:
            cin >> x;
            A.insert(x);
            sum += x;
            xor_ ^= x;
            break;
        case 2:
            cin >> x;
            A.erase(A.find(x));
            sum -= x;
            xor_ ^= x;
            break;
        case 3:
            cout << sum << "\n";
            break;
        case 4:
            cout << xor_ << "\n";
            break;
        }
    }

    return 0;
}