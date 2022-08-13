#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vpii = vector<pair<int, int>>;

vvi cache;

int solve(const vpii &matrix, int start, int end)
{
    //[start, end]범위의 최솟값을 리턴한다.
    int &ret = cache[start][end];

    if (ret != INT_MAX)
    {
        return ret;
    }

    if (start == end)
    {
        return ret = 0;
    }

    for (int i = start; i < end; i++)
    {
        ret = min(ret, solve(matrix, start, i) + solve(matrix, i + 1, end) + matrix[start].first * matrix[i + 1].first * matrix[end].second);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    cache = vvi(N + 1, vi(N + 1, INT_MAX));
    vpii matrix(N + 1);

    for (int i = 1; i < N + 1; i++)
    {
        int r, c;
        cin >> r >> c;
        matrix[i] = {r, c};
    }

    cout << solve(matrix, 1, N) << "\n";

    return 0;
}