#include <bits/stdc++.h>
using namespace std;

using vvll = vector<vector<long long>>;

void floyd_warshall(vvll &graph)
{
    int n = graph.size();
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][k] == INT_MAX || graph[k][j] == INT_MAX)
                    continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}