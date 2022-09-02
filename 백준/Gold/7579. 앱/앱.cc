#include <bits/stdc++.h>

using namespace std;

/* Macros */
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define eps 1e-9
#define inf (numeric_limits<int>::max() / 4)
#define llinf (numeric_limits<long long>::max() / 4)

/* Types Aliases */
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define umap unordered_map
#define uset unordered_set
#define ummap unordered_multimap
#define umset unordered_multiset
#define mmap multimap
#define mset multiset

/* Utils */
template <typename T>
struct reversion_wrapper
{
    T &iterable;
};

template <typename T>
auto begin(reversion_wrapper<T> w) { return std::rbegin(w.iterable); }

template <typename T>
auto end(reversion_wrapper<T> w) { return std::rend(w.iterable); }

template <typename T>
reversion_wrapper<T> reversed(T &&iterable) { return {iterable}; }
/* End Template */

int dp[101][10001] = {}; // dp[i][j] = i까지 비용이 j일 때 확보할 수 있는 최대 메모리
ll m[101] = {};
int c[101] = {};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    ll sum = 0;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> m[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> c[i];
        sum += c[i];
    }

    ll result = llinf;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j >= c[i])
                dp[i][j] = max<int>(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
            else
                dp[i][j] = dp[i - 1][j];

            if (dp[i][j] >= M)
                result = min<ll>(result, j);
        }
    }
    cout << result << "\n";

    return 0;
}