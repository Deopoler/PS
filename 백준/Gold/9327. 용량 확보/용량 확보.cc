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

int cache[101][2000 * 100 + 1];
int N;
int E;
int S[101];

int solve(int current, int disk)
{
    if (current == N)
    {
        if (disk * 2 >= E)
            return disk;
        else
            return inf;
    }

    if (cache[current][disk] != -1)
    {
        return cache[current][disk];
    }

    int &ret = cache[current][disk];
    return ret = min(solve(current + 1, disk + S[current]), solve(current + 1, disk));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> N >> E;
        memset(cache, -1, sizeof(cache));
        for (int i = 0; i < N; i++)
        {
            cin >> S[i];
        }

        int result = solve(0, 0);
        if (result == inf)
        {
            cout << "FULL\n";
        }
        else
        {
            cout << result << "\n";
        }
    }

    return 0;
}