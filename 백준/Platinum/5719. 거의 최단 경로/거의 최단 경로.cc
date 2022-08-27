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

// 인접행렬 구현
using ll = long long;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vb = vector<bool>;
void dijkstra(vvll &graph, vll &distance, int start)
{
    vector<bool> visited(graph.size(), false);
    visited[start] = true;
    for (int i = 0; i < sz(graph); i++)
    {
        distance[i] = graph[start][i];
    }

    int n = sz(graph);
    while (n--)
    {
        int current = 0;
        ll min = llinf;
        for (int i = 0; i < sz(graph); i++) // 최소비용을 가진 노드 찾기
        {
            if (distance[i] < min && !visited[i])
            {
                min = distance[i];
                current = i;
            }
        }
        visited[current] = true; // 최소비용 가진 노드 방문표시

        for (int i = 0; i < sz(graph); i++) // 비용 갱신
        {
            if (!visited[i])
            {
                if (distance[current] + graph[current][i] < distance[i])
                {
                    distance[i] = distance[current] + graph[current][i];
                }
            }
        }
    }
}

void removeEdges(vvll &graph, vll &distance, vb &visited, int dest)
{
    if (visited[dest])
        return;
    visited[dest] = true;
    for (int i = 0; i < sz(graph); i++)
    {
        if (dest == i)
            continue;
        if (graph[i][dest] + distance[i] == distance[dest])
        {
            graph[i][dest] = llinf;
            removeEdges(graph, distance, visited, i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1)
    {
        int N, M;
        cin >> N >> M;
        if (N == 0)
        {
            break;
        }
        int start, dest;
        cin >> start >> dest;
        vvll graph(N, vector<ll>(N, llinf));
        for (int i = 0; i < M; i++)
        {
            int u, v, p;
            cin >> u >> v >> p;
            graph[u][v] = p;
        }
        for (int i = 0; i < N; i++)
        {
            graph[i][i] = 0;
        }

        vll distance(N, llinf);

        // 첫번째 최단 경로 지우기
        dijkstra(graph, distance, start);

        vb visited(sz(graph));
        removeEdges(graph, distance, visited, dest);

        distance = vll(N, llinf);

        // 두번째 최단 경로 찾기
        dijkstra(graph, distance, start);
        if (distance[dest] != llinf)
        {
            cout << distance[dest] << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }

    return 0;
}
