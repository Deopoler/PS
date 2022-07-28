#include <bits/stdc++.h>
using namespace std;

using vvi = vector<vector<int>>;
using vl = vector<long long>;
using vvb = vector<bool>;

void bfs(vvi &graph, vl &distance, int start)
{
    queue<int> q;
    q.push(start);
    distance[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        // 노드 처리

        for (auto &&next : graph[node])
        {
            if (distance[node] + 1 < distance[next])
            {
                distance[next] = distance[node] + 1;
                q.push(next);
            }
        }
    }
}

int bfs(vvi &graph, vvb &visited, int start, int target)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty())
    {
        auto [node, distance] = q.front();
        q.pop();
        // 노드 처리

        for (auto &&next : graph[node])
        {
            if (next == target)
                return distance + 1;
            if (visited[next])
                continue;

            visited[next] = true;
            q.push({next, distance + 1});
        }
    }
}
