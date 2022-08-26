#include <bits/stdc++.h>

using namespace std;

int W, H;
using ll = long long;
using vstr = vector<string>;
using vvb = vector<vector<bool>>;
using vvll = vector<vector<long long>>;
using vvi = vector<vector<int>>;

int drow[4] = {0, 0, 1, -1};
int dcol[4] = {1, -1, 0, 0};

void bfs(vstr &graph, vvb &visited, vvll &distance, int startRow, int startCol)
{
    queue<pair<int, int>> q;
    q.push({startRow, startCol});
    visited[startRow][startCol] = true;
    distance[startRow][startCol] = 0;

    while (!q.empty())
    {
        auto [row, col] = q.front();
        q.pop();
        // 노드 처리

        for (int i = 0; i < 4; i++)
        {
            int next_row = row + drow[i];
            int next_col = col + dcol[i];
            if (next_row < 0 || next_row >= graph.size() || next_col < 0 || next_col >= graph[0].size() || visited[next_row][next_col] || graph[next_row][next_col] == 'x')
                continue;
            visited[next_row][next_col] = true;
            distance[next_row][next_col] = distance[row][col] + 1;
            q.push({next_row, next_col});
        }
    }
}
ll shortestPath(vvll &cache, vvll &dist, int visited, int current)
{
    ll &ret = cache[current][visited];
    if (ret != -1)
        return ret;

    if (visited == ((1 << dist.size()) - 1))
        return ret = 0;

    ret = LONG_LONG_MAX;

    for (int next = 0; next < dist.size(); next++)
    {
        if (visited & (1 << next))
            continue;
        ret = min(ret, dist[current][next] + shortestPath(cache, dist, visited | (1 << next), next));
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1)
    {
        cin >> W;
        cin >> H;
        if (W == 0)
            break;

        vstr graph(H);
        pair<int, int> startPos;
        vector<pair<int, int>> dirtyPos;
        for (int i = 0; i < H; i++)
        {
            cin >> graph[i];

            for (int j = 0; j < W; j++)
            {
                if (graph[i][j] == 'o')
                {
                    startPos = {i, j};
                }
                else if (graph[i][j] == '*')
                    dirtyPos.push_back({i, j});
            }
        }

        vvll dist(dirtyPos.size() + 1, vector<ll>(dirtyPos.size() + 1));
        vvb visited(H, vector<bool>(W, false));
        vvll distance(H, vector<ll>(W, -1));
        bfs(graph, visited, distance, startPos.first, startPos.second);
        for (int i = 0; i < dirtyPos.size(); i++)
        {
            dist[0][i + 1] = distance[dirtyPos[i].first][dirtyPos[i].second];
        }

        for (int i = 0; i < dirtyPos.size(); i++)
        {
            visited = vvb(H, vector<bool>(W, false));
            distance = vvll(H, vector<ll>(W));
            bfs(graph, visited, distance, dirtyPos[i].first, dirtyPos[i].second);
            dist[i + 1][0] = distance[startPos.first][startPos.second];
            for (int j = 0; j < dirtyPos.size(); j++)
            {
                dist[i + 1][j + 1] = distance[dirtyPos[j].first][dirtyPos[j].second];
            }
        }
        bool valid = true;
        for (auto &&i : dist)
        {
            for (auto &&j : i)
            {
                if (j == -1)
                {
                    valid = false;
                }
            }
        }
        if (not valid)
        {
            cout << "-1\n";
            continue;
        }

        vvll cache(dist.size(), vector<ll>((1 << dist[0].size()), -1));
        ll result = shortestPath(cache, dist, 1, 0);

        cout << result << "\n";
    }

    return 0;
}