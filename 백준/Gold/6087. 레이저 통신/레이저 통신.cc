#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#include <bits/stdc++.h>
using namespace std;

using vstr = vector<string>;
using vvall = vector<vector<array<long long, 4>>>;
using vall = vector<array<long long, 4>>;

int drow[4] = {0, 0, 1, -1};
int dcol[4] = {1, -1, 0, 0};

void bfs(vstr &graph, vvall &distance, int startRow, int startCol)
{
    deque<array<int, 3>> q; // [row][col][direction]
    q.push_back({startRow, startCol, 0});
    q.push_back({startRow, startCol, 1});
    q.push_back({startRow, startCol, 2});
    q.push_back({startRow, startCol, 3});
    distance[startRow][startCol][0] = 0LL;
    distance[startRow][startCol][1] = 0LL;
    distance[startRow][startCol][2] = 0LL;
    distance[startRow][startCol][3] = 0LL;

    while (!q.empty())
    {
        auto [row, col, direction] = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int next_row = row + drow[i];
            int next_col = col + dcol[i];
            if (next_row < 0 || next_row >= graph.size() || next_col < 0 || next_col >= graph[0].size() || graph[next_row][next_col] == '*')
                continue;
            int w;
            if (direction != i)
            {
                w = 1;
            }
            else
            {
                w = 0;
            }

            if (distance[row][col][direction] + w < distance[next_row][next_col][i])
            {
                if (w == 1)
                {
                    distance[next_row][next_col][i] = distance[row][col][direction] + 1;
                    q.push_back({next_row, next_col, i});
                }
                else
                {
                    distance[next_row][next_col][i] = distance[row][col][direction];
                    q.push_front({next_row, next_col, i});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int w, h;
    cin >> w >> h;

    vstr graph(h);
    vvall distance(h, vall(w, {4321, 4321, 4321, 4321}));

    int startRow = -1;
    int startCol = -1;
    int endRow = -1;
    int endCol = -1;
    for (int i = 0; i < h; i++)
    {
        cin >> graph[i];
        for (int j = 0; j < w; j++)
        {
            if (graph[i][j] == 'C')
            {
                if (startRow == -1)
                {
                    startRow = i;
                    startCol = j;
                }
                else
                {
                    endRow = i;
                    endCol = j;
                }
            }
        }
    }

    bfs(graph, distance, startRow, startCol);

    cout << *min_element(distance[endRow][endCol].begin(), distance[endRow][endCol].end()) << "\n";

    return 0;
}