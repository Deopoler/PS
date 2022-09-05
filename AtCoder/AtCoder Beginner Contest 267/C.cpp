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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<ll> A(N + 1, 0);
    vector<ll> sum(N + 1, 0);
    cin >> A[1];
    sum[1] = A[1];
    for (int i = 2; i <= N; i++)
    {
        cin >> A[i];
        sum[i] = sum[i - 1] + A[i];
    }

    ll current = 0;
    for (int i = 1; i <= M; i++)
    {
        current += i * A[i];
    }

    ll result = current;
    for (int i = M + 1; i <= N; i++)
    {
        current = current - sum[i - 1] + sum[i - M - 1] + M * A[i];
        result = max(result, current);
    }

    cout << result << "\n";

    return 0;
}