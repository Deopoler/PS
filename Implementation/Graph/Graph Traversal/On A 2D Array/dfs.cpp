#include <bits/stdc++.h>
using namespace std;

using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;

int drow[4] = {0, 0, 1, -1};
int dcol[4] = {1, -1, 0, 0};

void dfs(vvi &graph, vvb &visited, int row, int col)
{
    if (row < 0 || row >= graph.size() || col < 0 || col >= graph[0].size() || visited[row][col])
        return;
    visited[row][col] = true;
    // 노드 처리
    for (int i = 0; i < 4; i++)
    {
        dfs(graph, visited, row + drow[i], col + dcol[i]);
    }
}