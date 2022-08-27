#include <bits/stdc++.h>

using namespace std;

/* Macros */
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define eps 1e-9
#define inf (numeric_limits<int>::max() / 4)
#define llinf (numeric_limits<long long>::max() / 4)

/* Types Alias */
using ll = long long;
using ull = unsigned long long;
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

#define mod 998244353

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    set<pair<int, int>> obstacles;
    int N;
    int M;
    int a, b, c, d, e, f;
    umap<int, umap<int, int>> cache;
    cin >> N >> M;
    cin >> a >> b >> c >> d >> e >> f;

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        obstacles.insert({x, y});
    }

    cache[0][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        umap<int, umap<int, int>> new_cache;
        for (auto [x, m] : cache)
        {
            for (auto [y, v] : m)
            {
                if (obstacles.find({x + a, y + b}) == obstacles.end())
                {
                    new_cache[x + a][y + b] += v;
                    new_cache[x + a][y + b] %= mod;
                }
                if (obstacles.find({x + c, y + d}) == obstacles.end())
                {
                    new_cache[x + c][y + d] += v;
                    new_cache[x + c][y + d] %= mod;
                }
                if (obstacles.find({x + e, y + f}) == obstacles.end())
                {
                    new_cache[x + e][y + f] += v;
                    new_cache[x + e][y + f] %= mod;
                }
            }
        }
        swap(cache, new_cache);
    }

    int result = 0;
    for (auto [x, m] : cache)
    {
        for (auto [y, a] : m)
        {
            result += a;
            result %= mod;
        }
    }

    cout << result << "\n";

    return 0;
}