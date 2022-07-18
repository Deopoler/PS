#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    bool founded = false;
    for (int i = 0; i < 3; i++)
    {
        if (count(s.begin(), s.end(), s[i]) == 1)
        {
            cout << s[i];
            founded = true;
            break;
        }
    }

    if (not founded)
    {
        cout << -1;
    }

    return 0;
}