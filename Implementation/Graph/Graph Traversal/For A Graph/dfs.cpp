#include <bits/stdc++.h>
using namespace std;

using vvi = vector<vector<int>>;
using vi = vector<int>;

void dfs(vvi &graph, vi &visited, int node)
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