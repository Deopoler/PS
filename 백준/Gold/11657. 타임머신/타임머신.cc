#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vtiii = vector<tuple<int, int, int>>;
using vll = vector<long long>;

bool bellman_ford(vtiii &graph, vll &distance, int start, int nodes)
{
    distance[start] = 0;
    for (int i = 0; i < nodes - 1; i++)
    {
        for (auto [from, next, w] : graph)
        {
            if (distance[from] == INT_MAX)
                continue;
            distance[next] = min(distance[next], distance[from] + w);
        }
    }

    for (auto [from, next, w] : graph)
    {
        if (distance[from] == INT_MAX)
            continue;
        if (distance[from] + w < distance[next])
            return true; // graph contains negative cycle
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vtiii graph(M);
    vll distance(N + 1, INT_MAX);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[i] = {a, b, c};
    }

    if (bellman_ford(graph, distance, 1, N))
    {
        cout << "-1\n";
    }
    else
    {
        for (int i = 2; i <= N; i++)
        {
            if (distance[i] != INT_MAX)
            {
                cout << distance[i] << "\n";
            }
            else
            {
                cout << "-1\n";
            }
        }
    }

    return 0;
}