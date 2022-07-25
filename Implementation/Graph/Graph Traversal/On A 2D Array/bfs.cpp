#include <bits/stdc++.h>
using namespace std;

int drow[4] = {0, 0, 1, -1};
int dcol[4] = {1, -1, 0, 0};

void bfs(vector<vector<int>> &graph, vector<vector<int>> &visited, int startRow, int startCol)
{
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
            if (visited[next_row][next_col] || next_row < 0 || next_row >= graph.size() || next_col < 0 || next_col >= graph[0].size())
                continue;
            visited[next_row][next_col] = true;
            q.push({next_row, next_col});
        }
    }
}
