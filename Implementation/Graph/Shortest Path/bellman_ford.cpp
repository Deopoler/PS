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
        if (distance[from] == INT_MAX)
            continue;
        if (distance[from] + w < distance[next])
            return true; // graph contains negative cycle
    }
    return false;
}