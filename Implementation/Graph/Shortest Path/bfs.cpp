#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &graph, vector<int> &distance, int start)
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

int bfs(vector<vector<int>> &graph, int start, int target)
{
    queue<pair<int, int>> q;
    q.push({start, 0});

    while (!q.empty())
    {
        auto [node, distance] = q.front();
        q.pop();
        // 노드 처리

        for (auto &&next : graph[node])
        {
            if (next == target)
                return distance + 1;
            q.push({next, distance + 1});
        }
    }
}
