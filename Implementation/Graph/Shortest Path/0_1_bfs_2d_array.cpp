#include <bits/stdc++.h>
using namespace std;

using vstr = vector<string>;
using vvll = vector<vector<long long>>;

int drow[4] = {0, 0, 1, -1};
int dcol[4] = {1, -1, 0, 0};

void bfs(vstr &graph, vvll &distance, int startRow, int startCol)
{
    deque<pair<int, int>> q;
    q.push_back({startRow, startCol});
    distance[startRow][startCol] = 0;

    while (!q.empty())
    {
        auto [row, col] = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int next_row = row + drow[i];
            int next_col = col + dcol[i];
            if (next_row < 0 || next_row >= graph.size() || next_col < 0 || next_col >= graph[0].size())
                continue;
            int w;
            if (1 /*1일 조건*/)
            {
                w = 1;
            }
            else
            {
                w = 0;
            }

            if (distance[row][col] + w < distance[next_row][next_col])
            {
                if (w == 1)
                {
                    distance[next_row][next_col] = distance[row][col] + 1;
                    q.push_back({next_row, next_col});
                }
                else
                {
                    distance[next_row][next_col] = distance[row][col];
                    q.push_front({next_row, next_col});
                }
            }
        }
    }
}
