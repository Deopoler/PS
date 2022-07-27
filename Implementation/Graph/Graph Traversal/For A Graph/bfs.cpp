#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

void bfs(Graph &graph, vector<bool> &visited, int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        // 노드 처리

        for (auto next : graph[node])
        {
            if (visited[next])
                continue;
            visited[next] = true;
            q.push(next);
        }
    }
}
