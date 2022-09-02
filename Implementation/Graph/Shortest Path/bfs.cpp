#include <bits/stdc++.h>
using namespace std;

using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vi = vector<int>;

void bfs(vvi &graph, vll &distance, int start)
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

int bfs(vvi &graph, vi &visited, int start, int target)
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
