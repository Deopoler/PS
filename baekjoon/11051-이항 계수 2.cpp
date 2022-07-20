#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<vector<int>> combination(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || i == j)
                combination[i][j] = 1;
            else
                combination[i][j] = (combination[i - 1][j - 1] + combination[i - 1][j]) % 10007;
        }
    }

    cout << combination[N][K];

    return 0;
}