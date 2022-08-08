#include <bits/stdc++.h>

using namespace std;

using vvi = vector<vector<int>>;
using vvb = vector<vector<array<bool, 2>>>;
using vvll = vector<vector<array<long long, 2>>>;

int drow[4] = {0, 0, 1, -1};
int dcol[4] = {1, -1, 0, 0};

void bfs(vvi &graph, vvb &visited, vvll &distance, int startRow, int startCol)
{
    queue<tuple<int, int, bool>> q;
    q.push({startRow, startCol, false});
    visited[startRow][startCol][0] = true;
    distance[startRow][startCol][0] = 1;

    while (!q.empty())
    {
        auto [row, col, broken] = q.front();
        q.pop();
        // 노드 처리

        for (int i = 0; i < 4; i++)
        {
            int next_row = row + drow[i];
            int next_col = col + dcol[i];
            if (next_row < 0 || next_row >= graph.size() || next_col < 0 || next_col >= graph[0].size() || visited[next_row][next_col][broken])
                continue;
            if (graph[next_row][next_col] == 0)
            {
                visited[next_row][next_col][broken] = true;
                distance[next_row][next_col][broken] = distance[row][col][broken] + 1;
                q.push({next_row, next_col, broken});
            }
            else
            {
                if (broken)
                    continue;
                visited[next_row][next_col][1] = true;
                distance[next_row][next_col][1] = distance[row][col][0] + 1;
                q.push({next_row, next_col, 1});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vvi graph(N, vector<int>(M));
    vvb visited(N, vector<array<bool, 2>>(M, {false, false}));
    vvll distance(N, vector<array<long long, 2>>(M, {-1, -1}));
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
        {
            graph[i][j] = temp[j] == '0' ? 0 : 1;
        }
    }

    bfs(graph, visited, distance, 0, 0);

    if (distance[N - 1][M - 1][0] == -1)
    {

        cout << distance[N - 1][M - 1][1] << "\n";
    }
    else if (distance[N - 1][M - 1][1] == -1)
    {

        cout << distance[N - 1][M - 1][0] << "\n";
    }
    else
    {
        cout << min(distance[N - 1][M - 1][0], distance[N - 1][M - 1][1]) << "\n";
    }
    return 0;
}