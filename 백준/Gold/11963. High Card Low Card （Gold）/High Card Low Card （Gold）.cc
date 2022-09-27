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

    int n;
    cin >> n;

    vector<int> a_first(n / 2);
    vector<int> a_last(n / 2);
    set<int> a;
    vector<int> b_first;
    vector<int> b_last;
    for (auto &&i : a_first)
    {
        cin >> i;
        a.insert(i);
    }
    for (auto &&i : a_last)
    {
        cin >> i;
        a.insert(i);
    }

    for (int i = 2 * n; i >= 1; i--)
    {
        if (a.find(i) == a.end())
        {
            if (b_first.size() < n / 2)
            {
                b_first.push_back(i);
            }
            else
            {
                b_last.push_back(i);
            }
        }
    }

    int count = 0;

    sort(all(a_first), [](auto &a, auto &b)
         { return a > b; });
    sort(all(b_first), [](auto &a, auto &b)
         { return a > b; });

    int b_pos = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (b_first[b_pos] > a_first[i])
        {
            count++;
            b_pos++;
        }
    }

    sort(all(a_last));
    sort(all(b_last));

    b_pos = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (b_last[b_pos] < a_last[i])
        {
            count++;
            b_pos++;
        }
    }

    cout << count << "\n";

    return 0;
}