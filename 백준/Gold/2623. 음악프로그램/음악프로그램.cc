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

using vvi = vector<vector<int>>;
using vi = vector<int>;

bool dfs(vvi &graph, vi &visited, vi &result, vi &finished, int node)
{
    visited[node] = 1;
    for (auto &&next : graph[node])
    {
        if (not visited[next])
            if (not dfs(graph, visited, result, finished, next))
                return false;

        if (not finished[next])
            return false; // 사이클이 있음
    }

    result.push_back(node);
    finished[node] = 1;
    return true;
}

vi topologicalSort(vvi &graph)
{
    int n = graph.size();
    vi visited(n, 0);
    vi result;
    vi finished(n, 0);

    for (int i = 1; i < n; i++)
    {
        if (not visited[i])
            if (not dfs(graph, visited, result, finished, i))
                return vi(); // 사이클이 있으면 빈 벡터 반환
    }
    reverse(all(result));
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vvi graph(N + 1);

    for (int i = 0; i < M; i++)
    {
        int C;
        cin >> C;
        int a;
        cin >> a;
        for (int i = 0; i < C - 1; i++)
        {
            int b;
            cin >> b;
            graph[a].push_back(b);
            a = b;
        }
    }

    vi result = topologicalSort(graph);
    if (result.size() != 0)
    {
        for (auto &&i : result)
        {
            cout << i << "\n";
        }
    }
    else
    {
        cout << "0\n";
    }

    return 0;
}