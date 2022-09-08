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

int sudoku[9][9];
vii zero_pos;

bool isvalid(int row, int col, int value)
{
    // 가로줄 확인
    for (int i = 0; i < 9; i++)
    {
        if (i == col)
            continue;
        if (sudoku[row][i] == value)
            return false;
    }

    // 세로줄 확인
    for (int i = 0; i < 9; i++)
    {
        if (i == row)
            continue;
        if (sudoku[i][col] == value)
            return false;
    }

    // 정사각형 확인
    for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++)
    {
        for (int j = col / 3 * 3; j < col / 3 * 3 + 3; j++)
        {
            if (i == row && j == col)
                continue;
            if (sudoku[i][j] == value)
                return false;
        }
    }
    return true;
}

bool solve(int current)
{
    if (current == zero_pos.size())
        return true;

    auto [row, col] = zero_pos[current];
    for (int i = 1; i <= 9; i++)
    {
        if (isvalid(row, col, i))
        {
            sudoku[row][col] = i;
            if (solve(current + 1))
                return true;
            sudoku[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < 9; j++)
        {
            sudoku[i][j] = row[j] - '0';
            if (sudoku[i][j] == 0)
            {
                zero_pos.push_back({i, j});
            }
        }
    }

    solve(0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j];
        }
        cout << "\n";
    }

    return 0;
}