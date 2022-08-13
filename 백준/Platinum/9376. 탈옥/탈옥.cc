#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using vstr = vector<string>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vpii = vector<pair<int, int>>;
using pii = pair<int, int>;

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
            if (graph[next_row][next_col] == '.' || graph[next_row][next_col] == '$')
                w = 0;
            else if (graph[next_row][next_col] == '#')
                w = 1;
            else
                w = 87654321; // 벽이면 거리를 INF로 설정

            if (distance[row][col] + w < distance[next_row][next_col])
            {
                if (w == 1)
                {
                    distance[next_row][next_col] = distance[row][col] + 1;
                    q.push_back({next_row, next_col});
                }
                else if (w == 0)
                {
                    distance[next_row][next_col] = distance[row][col];
                    q.push_front({next_row, next_col});
                }
            }
        }
    }
}

void solve()
{
    int h, w;
    cin >> h >> w;
    vstr graph(h + 2);
    vvll distance1(h + 2, vll(w + 2, 87654321));
    vvll distance2(h + 2, vll(w + 2, 87654321));
    vvll distance3(h + 2, vll(w + 2, 87654321));
    vpii start;
    graph[0] = string(w + 2, '.');
    for (int i = 1; i < h + 1; i++)
    {
        cin >> graph[i];
        graph[i] = '.' + graph[i] + '.';
    }
    graph[h + 1] = string(w + 2, '.');

    for (int i = 0; i < h + 2; i++)
    {
        for (int j = 0; j < w + 2; j++)
        {
            if (graph[i][j] == '$')
            {
                start.push_back({i, j});
            }
        }
    }

    bfs(graph, distance1, start[0].first, start[0].second);
    bfs(graph, distance2, start[1].first, start[1].second);
    bfs(graph, distance3, 0, 0);

    ll result = 87654321;
    for (int i = 0; i < h + 2; i++)
    {
        for (int j = 0; j < w + 2; j++)
        {
            if (graph[i][j] == '#')
            {
                result = min(result, distance1[i][j] + distance2[i][j] + distance3[i][j] - 2);
            }
            else if (graph[i][j] == '.')
            {
                result = min(result, distance1[i][j] + distance2[i][j] + distance3[i][j]);
            }
        }
    }

    cout << result << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve();
    }

    return 0;
}