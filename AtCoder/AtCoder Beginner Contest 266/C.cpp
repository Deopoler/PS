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

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    int op = a.first * b.second + b.first * c.second + c.first * a.second;
    op -= (a.second * b.first + b.second * c.first + c.second * a.first);
    if (op > 0)
        return 1;
    else if (op == 0)
        return 0;
    else
        return -1;
}

int isIntersect(pair<pair<int, int>, pair<int, int>> x, pair<pair<int, int>, pair<int, int>> y)
{
    pair<int, int> a = x.first;
    pair<int, int> b = x.second;
    pair<int, int> c = y.first;
    pair<int, int> d = y.second;
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0)
    {
        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pair<int, int> A;
    pair<int, int> B;
    pair<int, int> C;
    pair<int, int> D;
    int x, y;
    cin >> x >> y;
    A = {x, y};
    cin >> x >> y;
    B = {x, y};
    cin >> x >> y;
    C = {x, y};
    cin >> x >> y;
    D = {x, y};

    if (!isIntersect({A, B}, {D, C}) && !isIntersect({A, D}, {B, C}) && isIntersect({A, C}, {B, D}))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}