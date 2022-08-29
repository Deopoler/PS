#include <bits/stdc++.h>

using namespace std;

/* Macros */
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define eps 1e-9
#define inf (numeric_limits<int>::max() / 4)
#define llinf (numeric_limits<long long>::max() / 4)

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

string result = "0";
int K;
string N;
void bfs(string start)
{
    queue<string> q;
    q.push(start);
    int current = 0;
    while (!q.empty() && current < K)
    {
        set<string> visited;
        int qs = sz(q);
        for (int i = 0; i < qs; i++)
        {
            auto node = q.front();
            q.pop();

            for (int i = 0; i < node.size() - 1; i++)
            {
                for (int j = i + 1; j < node.size(); j++)
                {
                    swap(node[i], node[j]);
                    if (visited.find(node) == visited.end())
                    {
                        if (node[0] != '0')
                        {
                            if (current + 1 == K)
                            {
                                result = max(result, node);
                            }
                            else
                            {
                                q.push(node);
                                visited.insert(node);
                            }
                        }
                    }
                    swap(node[i], node[j]);
                }
            }
        }
        current++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    bfs(N);

    if (result == "0")
    {
        cout << "-1\n";
    }
    else
    {
        cout << result << "\n";
    }

    return 0;
}