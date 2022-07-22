#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    cin >> S;

    set<string> A;

    for (int i = 0; i < S.length(); i++)
    {
        for (int j = 1; j < S.length() - i + 1; j++)
        {
            A.insert(S.substr(i, j));
        }
    }
    cout << A.size() << "\n";

    return 0;
}