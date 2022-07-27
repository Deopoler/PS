#include <bits/stdc++.h>

using namespace std;

int maxLen;
int maxNode;

void dfs(vector<vector<pair<int, int>>> &graph, int node, int e, int distance)
{
    for (auto [n, w] : graph[node])
    {
        if (n == e)
            continue;
        if (distance + w > maxLen)
        {
            maxLen = distance + w;
            maxNode = n;
        }
        dfs(graph, n, node, distance + w);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v;
    cin >> v;
    vector<vector<pair<int, int>>> graph(v + 1);
    for (int i = 0; i < v; i++)
    {
        int a;
        cin >> a;
        while (1)
        {

            int b, c;
            cin >> b;
            if (b != -1)
            {
                cin >> c;
                graph[a].push_back({b, c});
            }
            else
            {
                break;
            }
        }
    }

    dfs(graph, 1, -1, 0);

    dfs(graph, maxNode, -1, 0);

    cout << maxLen << "\n";

    return 0;
}