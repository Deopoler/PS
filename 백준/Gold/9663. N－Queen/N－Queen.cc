#include <bits/stdc++.h>

using namespace std;

int col[15];
int result = 0;

bool check(int r)
{
    for (int i = 0; i < r; i++)
    {
        if (col[i] == col[r] || abs(col[i] - col[r]) == r - i)
            return false;
    }
    return true;
}

void find(int r, int n)
{
    if (r == n)
    {
        result++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        col[r] = i;
        if (check(r))
        {
            find(r + 1, n);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    find(0, n);

    cout << result << "\n";

    return 0;
}