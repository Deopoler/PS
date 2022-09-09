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
using ld = long double;
#define umap unordered_map
#define uset unordered_set
#define ummap unordered_multimap
#define umset unordered_multiset
#define mmap multimap
#define mset multiset
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vii = vector<pair<int, int>>;
using vvii = vector<vector<pair<int, int>>>;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

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

void dfs(vvii &tree, vll &distance, int node, int e)
{
    for (auto [n, w] : tree[node])
    {
        if (n == e)
            continue;
        distance[n] = min(distance[node], (ll)w);
        dfs(tree, distance, n, node);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    vvii tree(N + 1);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        tree[a].push_back({b, w});
        tree[b].push_back({a, w});
    }

    while (Q--)
    {
        vll distance(N + 1, 0);
        int k, v;
        cin >> k >> v;
        distance[v] = llinf;
        dfs(tree, distance, v, v);

        int count = 0;
        for (auto &&i : distance)
        {
            if (i >= k)
                count++;
        }
        cout << count - 1 << "\n";
    }

    return 0;
}