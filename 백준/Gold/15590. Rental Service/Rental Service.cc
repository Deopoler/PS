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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    vll milk(n);
    for (auto &&i : milk)
    {
        cin >> i;
    }
    vector<pair<ll, ll>> store(m);
    for (auto &&i : store)
    {
        ll a, b;
        cin >> a >> b;
        i = {a, b};
    }
    vll farmers(r);
    for (auto &&i : farmers)
    {
        cin >> i;
    }

    sort(all(milk), greater<ll>());
    sort(all(store), [](auto a, auto b)
         { return a.second > b.second; });
    sort(all(farmers), greater<ll>());

    vll sell(n);
    int current_store = 0;
    for (int i = 0; i < n; i++)
    {
        sell[i] = i == 0 ? 0 : sell[i - 1];

        while (current_store < m && store[current_store].first <= milk[i])
        {
            sell[i] += store[current_store].first * store[current_store].second;
            milk[i] -= store[current_store].first;
            current_store++;
        }
        if (current_store < m && store[current_store].first > milk[i])
        {
            store[current_store].first -= milk[i];
            sell[i] += milk[i] * store[current_store].second;
        }
    }

    vll rent(n);
    rent[n - 1] = farmers[0];
    int current_farmer = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (current_farmer < r)
            rent[i] = rent[i + 1] + farmers[current_farmer++];
        else
            rent[i] = rent[i + 1];
    }
    ll result = 0;
    for (int i = 0; i < n - 1; i++)
    {
        result = max(result, sell[i] + rent[i + 1]);
        // cout << sell[i] << " " << rent[i] << "\n";
        // cout << result << '\n';
    }
    // cout << sell[n - 1] << " " << rent[n - 1] << "\n";
    result = max(result, sell[n - 1]);
    result = max(result, rent[0]);

    cout << result << "\n";

    return 0;
}