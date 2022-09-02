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
using vii = vector<pair<int, int>>;
using ii = pair<int, int>;

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

int order = 0;
int grouped = 0;
void dfs(vvi &graph, vi &finished, vi &discovered, int node)
{
    discovered[node] = order++;

    for (auto n : graph[node])
    {
        if (discovered[n] == -1)
            dfs(graph, finished, discovered, n);

        else if (not finished[n])
            grouped += discovered[node] - discovered[n] + 1;
    }

    finished[node] = true;
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
        int n;
        cin >> n;
        vvi graph(n + 1);
        vi finished(n + 1, false);
        vi discovered(n + 1, -1);
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            graph[i].push_back(a);
        }
        order = 0;
        grouped = 0;

        for (int i = 1; i <= n; i++)
        {
            if (discovered[i] == -1)
                dfs(graph, finished, discovered, i);
        }

        cout << n - grouped << "\n";
    }

    return 0;
}