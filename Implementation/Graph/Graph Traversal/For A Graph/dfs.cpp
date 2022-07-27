#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

void dfs(Graph &graph, vector<bool> &visited, int node)
{
    if (visited[node])
        return;
    visited[node] = true;
    // 노드 처리

    for (auto n : graph[node])
    {
        dfs(graph, visited, n);
    }
}