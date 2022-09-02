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

class Union_Find
{
private:
    int *link;
    int *size;

public:
    Union_Find(int n)
    {
        link = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++)
        {
            link[i] = i;
            size[i] = 1;
        }
    }

    int find(int x)
    {
        if (x == link[x])
            return x;
        return link[x] = find(link[x]);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (size[a] < size[b])
            swap(a, b);
        size[a] += size[b];
        link[b] = a;
    }

    bool same(int a, int b)
    {
        return find(a) == find(b);
    }

    int getsize(int x)
    {
        return size[find(x)];
    }
};

using viii = vector<tuple<int, int, int>>;

int kruskal(viii &graph, int nodes, viii &mst)
{
    int result = 0;
    sort(
        graph.begin(), graph.end(), [](const auto &a, const auto &b)
        { return get<2>(a) < get<2>(b); });
    Union_Find uf(nodes + 1);
    for (auto [a, b, w] : graph)
    {
        if (!uf.same(a, b))
        {
            mst.push_back({a, b, w});
            result += w;
            uf.unite(a, b);
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    viii graph(M);
    for (int i = 0; i < M; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[i] = {a, b, w};
    }
    viii mst;
    int result = kruskal(graph, N, mst);

    int final_result = inf;

    for (auto [a, b, w] : mst)
    {
        final_result = min(final_result, result - w);
    }

    cout << final_result << '\n';

    return 0;
}