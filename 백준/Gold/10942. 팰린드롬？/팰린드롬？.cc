#include <bits/stdc++.h>

#define MAX 2000
using namespace std;

int dp[MAX + 1][MAX + 1];
int arr[MAX + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    for (int i = N; i > 0; i--)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                dp[i][j] = true;
            else if (i + 1 == j)
                dp[i][j] = arr[i] == arr[j];
            else
                dp[i][j] = dp[i + 1][j - 1] && (arr[i] == arr[j]);
        }
    }

    int M;
    cin >> M;
    int S, E;
    while (M--)
    {
        cin >> S >> E;
        cout << dp[S][E] << "\n";
    }

    return 0;
}