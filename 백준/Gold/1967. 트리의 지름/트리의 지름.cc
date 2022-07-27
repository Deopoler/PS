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

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dfs(graph, 1, -1, 0);

    dfs(graph, maxNode, -1, 0);

    cout << maxLen << "\n";

    return 0;
}