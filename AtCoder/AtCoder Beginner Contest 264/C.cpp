#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvpii = vector<vector<pair<int, int>>>;
using vpii = vector<pair<int, int>>;
using pii = pair<int, int>;

pii find(const vvi &matrix, int value, int minRow, int minCol)
{
    for (int i = minRow; i < matrix.size(); i++)
    {
        for (int j = minCol; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == value)
                return {i, j};
        }
    }

    return {-1, -1};
}

bool solve(const vvi &A, const vvi &B, vvpii &pos)
{
    for (int i = 0; i < B.size(); i++)
    {
        for (int j = 0; j < B[0].size(); j++)
        {
            if (i == 0 && j == 0)
            {
                pos[i][j] = find(A, B[i][j], 0, 0);
            }
            else if (i == 0)
            {
                pos[i][j] = find(A, B[i][j], 0, pos[i][j - 1].second + 1);
            }
            else if (j == 0)
            {
                pos[i][j] = find(A, B[i][j], pos[i - 1][j].first + 1, 0);
            }
            else
            {
                pos[i][j] = find(A, B[i][j], pos[i - 1][j].first + 1, pos[i][j - 1].second + 1);
            }
            if (pos[i][j].first == -1)
                return false;
        }
    }

    for (int i = 0; i < B.size(); i++)
    {
        for (int j = 0; j < B[0].size(); j++)
        {
            if (pos[i][j].first != pos[i][0].first || pos[i][j].second != pos[0][j].second)
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h1, w1;
    cin >> h1 >> w1;
    vvi A(h1, vi(w1));
    for (int i = 0; i < h1; i++)
    {
        for (int j = 0; j < w1; j++)
        {
            cin >> A[i][j];
        }
    }

    int h2, w2;
    cin >> h2 >> w2;
    vvi B(h2, vi(w2));
    vvpii pos(h2, vpii(w2));
    for (int i = 0; i < h2; i++)
    {
        for (int j = 0; j < w2; j++)
        {
            cin >> B[i][j];
        }
    }
    bool result = solve(A, B, pos);

    // for (auto &&i : pos)
    // {
    //     for (auto &&[a, b] : i)
    //     {
    //         cout << "{" << a << "," << b << "} ";
    //     }
    //     cout << "\n";
    // }

    if (result)
    {
        cout << "Yes"
             << "\n";
    }
    else
    {
        cout << "No"
             << "\n";
    }

    return 0;
}