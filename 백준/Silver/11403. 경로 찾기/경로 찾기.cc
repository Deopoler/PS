#include <bits/stdc++.h>

using namespace std;

void floyd_warshall(vector<vector<int>> &graph)
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int w;
            cin >> w;
            if (w == 0)
            {
                graph[i][j] = INT_MAX;
            }
            else
            {
                graph[i][j] = w;
            }
        }
    }

    floyd_warshall(graph);

    for (auto &&i : graph)
    {
        for (auto &&j : i)
        {
            if (j == INT_MAX)
            {
                cout << "0 ";
            }
            else
            {
                cout << "1 ";
            }
        }
        cout << "\n";
    }

    return 0;
}