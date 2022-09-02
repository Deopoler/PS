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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for (auto &i : A)
    {
        cin >> i;
    }

    int start = 0;
    int end = 1;
    int sum = A[0];
    int best = inf;

    while (start != N)
    {
        if (end == N || sum >= S)
        {
            if (sum >= S)
                best = min(best, end - start);
            sum -= A[start];
            start++;
        }
        else
        {
            sum += A[end];
            end++;
        }
    }
    if (best == inf)
        cout << "0\n";
    else
        cout << best << "\n";

    return 0;
}