#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAX = (int)1e5 + 1;
ll cache[MAX][5];
pair<int, int> snuke[MAX];
ll solve(int time, int pos)
{
    if (time == MAX || pos < 0 || pos > 4)
        return 0;
    ll &ret = cache[time][pos];
    if (ret != -1)
        return ret;

    ret = solve(time + 1, pos);
    ret = max(ret, solve(time + 1, pos - 1));
    ret = max(ret, solve(time + 1, pos + 1));
    if (snuke[time].first == pos)
        ret += snuke[time].second;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    memset(cache, -1, sizeof(cache));

    for (int i = 0; i < MAX; i++)
    {
        snuke[i] = {-1, -1};
    }

    int t, x, a;
    for (int i = 0; i < N; i++)
    {
        cin >> t >> x >> a;
        snuke[t] = {x, a};
    }

    cout << solve(0, 0) << "\n";

    return 0;
}