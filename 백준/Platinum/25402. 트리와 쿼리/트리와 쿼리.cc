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
using vvi = vector<vi>;
using vii = vector<pair<int, int>>;
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

class Union_Find
{
public:
    int *link;
    int *size;
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

    ~Union_Find()
    {
        delete[] link;
        delete[] size;
    }
};

void treeToDAG(vvi &tree, vi &parent, int node)
{
    for (int n : tree[node])
    {
        if (n != parent[node])
        {
            parent[n] = node;
            treeToDAG(tree, parent, n);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vvi tree(N + 1);
    vi parent(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    treeToDAG(tree, parent, 1);

    int Q;
    cin >> Q;
    Union_Find uf(N + 1);
    vi visited(N + 1, false);
    vector<int> inS(N + 1, false);
    while (Q--)
    {
        int K;
        cin >> K;
        vector<int> vecS(K);
        for (int i = 0; i < K; i++)
        {
            int a;
            cin >> a;
            inS[a] = true;
            vecS[i] = a;
        }
        for (auto &&n : vecS)
        {
            int p = parent[n];
            if (inS[p])
                uf.unite(p, n);
        }

        ll result = 0;
        for (auto &&n : vecS)
        {
            if (uf.find(n) != n)
                continue;
            ll size = uf.getsize(n);
            result += size * (size - 1) / 2;
        }

        cout << result << "\n";
        for (auto &&i : vecS)
        {
            uf.link[i] = i;
            uf.size[i] = 1;
            visited[i] = false;
            inS[i] = false;
        }
    }

    return 0;
}