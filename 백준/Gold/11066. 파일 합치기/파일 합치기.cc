#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;

vvi cache;
vi sum;

int solve(const vi &file, int start, int end)
{
    //[start, end]범위의 최솟값을 리턴한다.
    int &ret = cache[start][end];

    if (ret != 987654321)
    {
        return ret;
    }

    if (start == end)
    {
        return ret = 0;
    }

    if (start + 1 == end)
    {
        return ret = file[start] + file[end];
    }

    for (int i = start; i < end; i++)
    {
        ret = min(ret, solve(file, start, i) + solve(file, i + 1, end));
    }

    ret += sum[end] - sum[start - 1];
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int K;
        cin >> K;
        cache = vvi(K + 1, vi(K + 1, 987654321));
        sum = vi(K + 1, 0);
        vi file(K + 1);

        for (int j = 1; j < K + 1; j++)
        {
            cin >> file[j];
            sum[j] = sum[j - 1] + file[j];
        }

        cout << solve(file, 1, K) << "\n";
    }

    return 0;
}