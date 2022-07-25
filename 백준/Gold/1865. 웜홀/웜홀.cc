#include <bits/stdc++.h>

using namespace std;

bool bellman_ford(vector<tuple<int, int, int>> &graph, vector<int> &distance, int start, int nodes)
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
        if (distance[from] == INT_MAX && next != start)
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

    int TC;
    cin >> TC;

    for (int i = 0; i < TC; i++)
    {
        int nodes, roads, wormholes;
        cin >> nodes >> roads >> wormholes;

        vector<tuple<int, int, int>> graph;
        vector<int> distance(nodes + 1, INT_MAX);

        for (int i = 0; i < roads; i++)
        {
            int S, E, T;
            cin >> S >> E >> T;
            graph.push_back({S, E, T});
            graph.push_back({E, S, T});
        }

        for (int i = 0; i < wormholes; i++)
        {
            int S, E, T;
            cin >> S >> E >> T;
            graph.push_back({S, E, -T});
        }
        bool result = false;
        for (int i = 1; i <= nodes; i++)
        {
            if (distance[i] == INT_MAX)
            {
                result |= bellman_ford(graph, distance, i, nodes);
            }
        }
        if (result)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }

        graph.clear();
        graph.shrink_to_fit();
        distance.clear();
        distance.shrink_to_fit();
    }

    return 0;
}