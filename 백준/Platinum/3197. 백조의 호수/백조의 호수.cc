#include <bits/stdc++.h>

using namespace std;

using vstr = vector<string>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vpii = vector<pair<int, int>>;
using pii = pair<int, int>;

class Union_Find
{
private:
    int *link;
    int *size;

public:
    Union_Find(int n)
    {
        link = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++)
        {
            link[i] = i;
            size[i] = 1;
        }
    }

    int find(int x)
    {
        if (x == link[x])
            return x;
        return link[x] = find(link[x]);
    }

    void unite(int a, int b)
    {
        if (a < 0 || b < 0)
            return;
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (size[a] < size[b])
            swap(a, b);
        size[a] += size[b];
        link[b] = a;
    }

    bool same(int a, int b)
    {
        if (a < 0 || b < 0)
            return false;
        return find(a) == find(b);
    }

    int getsize(int x)
    {
        return size[find(x)];
    }
};

int drow[4] = {0, 0, 1, -1};
int dcol[4] = {1, -1, 0, 0};

void dfs(const vstr &graph, int row_1, int col_1, int row, int col, Union_Find &uf)
{
    if (row < 0 || row >= graph.size() || col < 0 || col >= graph[0].size() || (graph[row][col] != '.' && graph[row][col] != 'L') || uf.same(row * graph[0].size() + col, row_1 * graph[0].size() + col_1))
        return;

    uf.unite(row * graph[0].size() + col, row_1 * graph[0].size() + col_1);
    for (int i = 0; i < 4; i++)
    {
        dfs(graph, row, col, row + drow[i], col + dcol[i], uf);
    }
}

int bfs(const vstr &graph, vvll &distance, const vpii &start, const pii &Lpos1, const pii &Lpos2, Union_Find &uf)
{
    if (uf.same(Lpos1.first * graph[0].size() + Lpos1.second, Lpos2.first * graph[0].size() + Lpos2.second))
    {
        return 0;
    }

    queue<pair<int, int>> q;
    for (auto [row, col] : start)
    {
        q.push({row, col});
        distance[row][col] = 0;
    }

    while (!q.empty())
    {
        auto [row, col] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_row = row + drow[i];
            int next_col = col + dcol[i];
            if (next_row < 0 || next_row >= graph.size() || next_col < 0 || next_col >= graph[0].size() || uf.same(next_row * graph[0].size() + next_col, row * graph[0].size() + col))
                continue;
            if (uf.same(row * graph[0].size() + col, Lpos1.first * graph[0].size() + Lpos1.second) && uf.same(next_row * graph[0].size() + next_col, Lpos2.first * graph[0].size() + Lpos2.second))
            {
                return max(distance[next_row][next_col], distance[row][col]);
            }
            if (uf.same(row * graph[0].size() + col, Lpos2.first * graph[0].size() + Lpos2.second) && uf.same(next_row * graph[0].size() + next_col, Lpos1.first * graph[0].size() + Lpos1.second))
            {
                return max(distance[next_row][next_col], distance[row][col]);
            }
            distance[next_row][next_col] = distance[row][col] + 1;
            uf.unite(next_row * graph[0].size() + next_col, row * graph[0].size() + col);
            q.push({next_row, next_col});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int R, C;
    cin >> R >> C;
    vstr graph(R);
    vvll distance(R, vll(C, -1));
    vpii start;

    bool find_first = false;
    pii Lpos1;
    pii Lpos2;

    Union_Find uf(R * C);
    for (int i = 0; i < R; i++)
    {
        cin >> graph[i];

        for (int j = 0; j < C; j++)
        {
            if (graph[i][j] == '.')
            {
                start.push_back({i, j});
            }
            else if (graph[i][j] == 'L')
            {
                start.push_back({i, j});
                if (!find_first)
                {
                    Lpos1 = {i, j};
                    find_first = true;
                }
                else
                {
                    Lpos2 = {i, j};
                }
            }
        }
    }

    for (auto [row, col] : start)
    {
        dfs(graph, -1, -1, row, col, uf);
    }

    int output = bfs(graph, distance, start, Lpos1, Lpos2, uf);
    cout << output << "\n";

    return 0;
}