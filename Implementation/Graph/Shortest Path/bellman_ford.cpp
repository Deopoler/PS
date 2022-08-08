#include <bits/stdc++.h>
using namespace std;

using vvi = vector<tuple<int, int, int>>;
using vll = vector<long long>;

bool bellman_ford(vvi &graph, vll &distance, int start, int nodes)
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