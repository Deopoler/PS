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

int t, a, b;

void bfs(vvi &visited, int start)
{
    queue<ii> q;
    q.push({start, 0});
    visited[start][0] = true;

    while (!q.empty())
    {
        auto [node, water] = q.front();
        q.pop();
        // 노드 처리

        if (water == 0)
        {
            int next = node / 2;
            if (next <= t && !visited[next][1])
            {
                visited[next][1] = true;
                q.push({next, 1});
            }
        }

        for (auto next : {node + a, node + b})
        {
            if (next > t)
                continue;
            if (!visited[next][water])
            {
                visited[next][water] = true;
                q.push({next, water});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t >> a >> b;

    vvi visited(t + 1, vi(2, false));

    bfs(visited, 0);

    for (int i = t; i >= 0; i--)
    {
        if (visited[i][0] || visited[i][1])
        {
            cout << i << "\n";
            return 0;
        }
    }

    return 0;
}