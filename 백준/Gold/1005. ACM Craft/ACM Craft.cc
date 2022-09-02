#include <bits/stdc++.h>

using namespace std;

/* Macros */
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define eps 1e-9
constexpr int inf = numeric_limits<int>::max() / 2;
constexpr long long llinf = numeric_limits<long long>::max() / 2;

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
using vi = vector<int>;
using vvi = vector<vi>;

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

#define MAX 1000
int cache[MAX];

int solve(vvi &graph, vi &D, int node)
{
    int &ret = cache[node];
    if (ret != -1)
        return ret;
    ret = 0;
    for (auto &&next : graph[node])
    {
        ret = max(ret, solve(graph, D, next));
    }

    return ret += D[node];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        memset(cache, -1, sizeof(cache));
        int N, K;
        cin >> N >> K;
        vvi graph(N);
        vi D(N);
        for (auto &i : D)
        {
            cin >> i;
        }

        for (int i = 0; i < K; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[b - 1].push_back(a - 1);
        }
        int W;
        cin >> W;
        cout << solve(graph, D, W - 1) << "\n";
    }

    return 0;
}