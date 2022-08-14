#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;

int drow[4] = {0, 0, 1, -1};
int dcol[4] = {1, -1, 0, 0};

bool bfs(vvi &graph, vvb &visited, int startRow, int startCol, int targetRow, int targetCol, int targetMin, int targetMax)
{
    if (graph[startRow][startCol] > targetMax || graph[startRow][startCol] < targetMin)
        return false;
    queue<pair<int, int>> q;
    q.push({startRow, startCol});
    visited[startRow][startCol] = true;

    while (!q.empty())
    {
        auto [row, col] = q.front();
        q.pop();
        // 노드 처리

        for (int i = 0; i < 4; i++)
        {
            int next_row = row + drow[i];
            int next_col = col + dcol[i];
            if (next_row < 0 || next_row >= graph.size() || next_col < 0 || next_col >= graph[0].size() || visited[next_row][next_col] ||
                graph[next_row][next_col] > targetMax || graph[next_row][next_col] < targetMin)
                continue;
            visited[next_row][next_col] = true;
            q.push({next_row, next_col});
        }
    }
    return visited[targetRow][targetCol];
}

bool check(vvi &graph, vvb &visited, int n, int diff)
{
    for (int i = 0; i <= 200; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                visited[j][k] = false;
            }
        }

        if (bfs(graph, visited, 0, 0, n - 1, n - 1, i, i + diff))
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vvi graph(n, vector<int>(n));
    vvb visited(n, vector<bool>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int lo = -1;
    int hi = 201;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        if (check(graph, visited, n, mid))
            hi = mid;
        else
            lo = mid;
    }

    cout << hi << "\n";

    return 0;
}