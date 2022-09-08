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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<ll> A(N);
    for (auto &&i : A)
    {
        cin >> i;
    }

    sort(all(A));

    ll result_value = llinf;
    array<ll, 3> result;
    for (int i = 0; i < N; i++)
    {
        int left = 0;
        int right = N - 1;
        while (left < right)
        {
            if (left == i)
            {
                left++;
                continue;
            }
            else if (right == i)
            {
                right--;
                continue;
            }

            if (abs(A[left] + A[right] + A[i]) < result_value)
            {
                result_value = abs(A[left] + A[right] + A[i]);
                result = {A[left], A[right], A[i]};
                sort(all(result));
            }
            else if (A[left] + A[right] + A[i] > 0)
                right--;
            else if (A[left] + A[right] + A[i] < 0)
                left++;
            else
                break;
        }
    }

    for (auto &&i : result)
    {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}