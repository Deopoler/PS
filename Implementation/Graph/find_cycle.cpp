#include <bits/stdc++.h>
using namespace std;

using vvi = vector<vector<int>>;
using vi = vector<int>;

int order = 0;
int grouped = 0;
void dfs(vvi &graph, vi &finished, vi &discovered, int node)
{
    discovered[node] = order++;

    for (auto n : graph[node])
    {
        if (discovered[n] == -1)
            dfs(graph, finished, discovered, n);

        else if (not finished[n])
            grouped += discovered[node] - discovered[n] + 1;
    }

    finished[node] = true;
}