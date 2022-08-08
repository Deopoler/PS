#include <bits/stdc++.h>
using namespace std;

using vvi = vector<vector<pair<int, int>>>;
using vll = vector<long long>;

void dijkstra(vvi &graph, vll &distance, int start)
{
    priority_queue<pair<int, int>> q;

    distance[start] = 0;
    q.push({0, start});
    while (!q.empty())
    {
        int node = q.top().second;
        q.pop();
        for (auto [next, w] : graph[node])
        {
            if (distance[node] + w < distance[next])
            {
                distance[next] = distance[node] + w;
                q.push({-distance[next], next}); // c++ priority queue는 최대 힙이기 때문에 거리에 -를 붙임
            }
        }
    }
}