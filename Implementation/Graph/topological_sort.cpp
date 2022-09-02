#include <bits/stdc++.h>

using namespace std;
#define all(x) x.begin(), x.end()

using vvi = vector<vector<int>>;
using vi = vector<int>;

bool dfs(vvi &graph, vi &visited, vi &result, vi &finished, int node)
{
    visited[node] = 1;
    for (auto &&next : graph[node])
    {
        if (not visited[next])
            if (not dfs(graph, visited, result, finished, next))
                return false;

        if (not finished[next])
            return false; // 사이클이 있음
    }

    result.push_back(node);
    finished[node] = 1;
    return true;
}

vi topologicalSort(vvi &graph)
{
    int n = graph.size();
    vi visited(n, 0);
    vi result;
    vi finished(n, 0);

    for (int i = 1; i < n; i++)
    {
        if (not visited[i])
            if (not dfs(graph, visited, result, finished, i))
                return vi(); // 사이클이 있으면 빈 벡터 반환
    }
    reverse(all(result));
    return result;
}