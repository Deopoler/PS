#include <bits/stdc++.h>
using namespace std;

int drow[4] = {0, 0, 1, -1};
int dcol[4] = {1, -1, 0, 0};

void dfs(vector<vector<int>> &graph, vector<vector<int>> &visited, int row, int col)
{
    if (visited[row][col] || row < 0 || row >= graph.size() || col < 0 || col >= graph[0].size())
        return;
    visited[row][col] = true;
    // 노드 처리
    for (int i = 0; i < 4; i++)
    {
        dfs(graph, visited, row + drow[i], col + dcol[i]);
    }
}