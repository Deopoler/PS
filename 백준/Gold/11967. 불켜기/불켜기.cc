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

int drow[4] = {0, 0, 1, -1};
int dcol[4] = {1, -1, 0, 0};

int bfs(vvi &lit, vvi &visited, const vvi &switches, int startRow, int startCol, int n)
{
    queue<pair<int, int>> q;
    q.push({startRow, startCol});
    visited[startRow][startCol] = true;
    int count = 0;
    for (auto &&i : switches[startRow * n + startCol])
    {
        if (!lit[i / n][i % n])
        {
            count++;
        }
        lit[i / n][i % n] = true;
    }

    while (!q.empty())
    {
        auto [row, col] = q.front();
        q.pop();
        // 노드 처리

        for (int i = 0; i < 4; i++)
        {
            int next_row = row + drow[i];
            int next_col = col + dcol[i];
            if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= n || visited[next_row][next_col] || !lit[next_row][next_col])
                continue;
            visited[next_row][next_col] = true;
            for (auto &&i : switches[next_row * n + next_col])
            {
                if (!lit[i / n][i % n])
                {
                    count++;
                }
                lit[i / n][i % n] = true;
            }
            q.push({next_row, next_col});
        }
    }

    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vvi switches(n * n);
    vvi lit(n, vi(n, false));
    vvi visited(n, vi(n, false));

    for (int i = 0; i < m; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        switches[(x - 1) * n + (y - 1)].push_back((a - 1) * n + (b - 1));
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << i << " " << j << ": ";
    //         for (auto &&k : switches[i * n + j])
    //         {
    //             cout << k / n << " " << k % n << ", ";
    //         }
    //         cout << "\n";
    //     }
    // }

    int last_value = 1;
    lit[0][0] = true;
    for (int i = 0; i < n * n; i++)
    {
        visited = vvi(n, vi(n, false));
        int temp = bfs(lit, visited, switches, 0, 0, n);
        if (temp == 0)
            break;
        else
            last_value += temp;
    }

    cout << last_value << "\n";

    return 0;
}