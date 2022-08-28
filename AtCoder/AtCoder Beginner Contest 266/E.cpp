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

#define MAX 101

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    ld current = 3.5;
    for (int i = 2; i <= N; i++)
    {
        ld temp = current * 3;
        temp += max<ld>(4, current);
        temp += max<ld>(5, current);
        temp += max<ld>(6, current);
        temp /= 6;
        current = temp;
    }
    cout << current << "\n";
    return 0;
}