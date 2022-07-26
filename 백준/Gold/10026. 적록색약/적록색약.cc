#include <bits/stdc++.h>

using namespace std;

int drow[4] = {0, 0, 1, -1};
int dcol[4] = {1, -1, 0, 0};

void dfs(vector<string> &graph, vector<vector<bool>> &visited, int row, int col, char target)
{
    if (row < 0 || row >= graph.size() || col < 0 || col >= graph[0].size() || visited[row][col] || graph[row][col] != target)
        return;
    visited[row][col] = true;
    // 노드 처리
    for (int i = 0; i < 4; i++)
    {
        dfs(graph, visited, row + drow[i], col + dcol[i], target);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<string> graph(N);
    vector<string> graph_red_green(N);
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        graph[i] = s;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'G')
            {
                s[i] = 'R';
            }
        }
        graph_red_green[i] = s;
    }

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (not visited[i][j])
            {
                count++;
                dfs(graph, visited, i, j, graph[i][j]);
            }
        }
    }

    cout << count << "\n";

    count = 0;
    visited = vector<vector<bool>>(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (not visited[i][j])
            {
                count++;
                dfs(graph_red_green, visited, i, j, graph_red_green[i][j]);
            }
        }
    }

    cout << count << "\n";

    return 0;
}