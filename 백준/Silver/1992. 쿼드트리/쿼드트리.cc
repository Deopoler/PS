#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

string quad_tree(vector<string> s, int r, int c, int n)
{
    bool all_same = true;
    char last = s[r][c];
    for (int i = r; i < r + n; i++)
    {
        for (int j = c; j < c + n; j++)
        {
            if (s[i][j] != last)
            {
                all_same = false;
                break;
            }
        }
        if (not all_same)
            break;
    }
    if (all_same)
    {
        return string(1, s[r][c]);
    }
    else
    {
        string top_left = quad_tree(s, r, c, n / 2);
        if (top_left.length() > 1)
        {
            top_left = "(" + top_left + ")";
        }
        string top_right = quad_tree(s, r, c + n / 2, n / 2);
        if (top_right.length() > 1)
        {
            top_right = "(" + top_right + ")";
        }
        string bottom_left = quad_tree(s, r + n / 2, c, n / 2);
        if (bottom_left.length() > 1)
        {
            bottom_left = "(" + bottom_left + ")";
        }
        string bottom_right = quad_tree(s, r + n / 2, c + n / 2, n / 2);
        if (bottom_right.length() > 1)
        {
            bottom_right = "(" + bottom_right + ")";
        }

        return top_left + top_right + bottom_left + bottom_right;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<string> s(N);
    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
    }
    string result = quad_tree(s, 0, 0, N);
    if (result.length() > 1)
    {
        result = "(" + result + ")";
    }
    cout << result;

    return 0;
}