#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using vstr = vector<string>;
using vvi = vector<vector<bool>>;
using vpii = vector<pair<int, int>>;
using pi = pair<int, int>;

int drow[4] = {0, 0, 1, -1};
int dcol[4] = {1, -1, 0, 0};

vvi isInAir(const vstr &cave, vvi &visited)
{
    queue<pair<int, int>> q;

    for (int i = 0; i < cave[0].size(); i++)
    {
        if (cave[cave.size() - 1][i] != 'x')
            continue;
        q.push({cave.size() - 1, i});
        visited[cave.size() - 1][i] = true;
    }

    while (!q.empty())
    {
        auto [row, col] = q.front();
        q.pop();
        // 노드 처리

        for (int i = 0; i < 4; i++)
        {
            int next_row = row + drow[i];
            int next_col = col + dcol[i];
            if (next_row < 0 || next_row >= cave.size() || next_col < 0 || next_col >= cave[0].size() || cave[next_row][next_col] != 'x' || visited[next_row][next_col])
                continue;
            visited[next_row][next_col] = true;
            q.push({next_row, next_col});
        }
    }

    vvi inair(cave.size(), vector<bool>(cave[0].size(), false));
    for (int i = 0; i < cave.size(); i++)
    {
        for (int j = 0; j < cave[0].size(); j++)
        {
            if ((!visited[i][j]) && cave[i][j] == 'x')
            {
                inair[i][j] = true;
            }
        }
    }
    return inair;
}

int howmanycango(const vvi &visited, const vvi &inair)
{
    for (int count = 1;; count++)
    {
        for (int i = 0; i < inair.size(); i++)
        {
            for (int j = 0; j < inair[0].size(); j++)
            {
                if (inair[i][j] && (i + count >= visited.size() || visited[i + count][j]))
                    return count - 1;
            }
        }
    }
}

void gravity(vstr &cave)
{
    vvi visited(cave.size(), vector<bool>(cave[0].size(), false));
    vvi inair = isInAir(cave, visited);

    bool isempty = true;
    for (auto &&i : inair)
    {
        for (auto &&j : i)
        {
            if (j)
            {
                isempty = false;
                break;
            }
        }
        if (!isempty)
            break;
    }
    if (isempty)
        return;

    int down = howmanycango(visited, inair);
    for (int i = inair.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < inair[0].size(); j++)

        {
            if (inair[i][j])
            {
                cave[i][j] = '.';
                cave[i + down][j] = 'x';
            }
        }
    }
}

void breakleft(vstr &cave, int height)
{
    for (int i = 0; i < cave[0].size(); i++)
    {
        if (cave[cave.size() - height][i] == 'x')
        {
            cave[cave.size() - height][i] = '.';
            return;
        }
    }
}

void breakright(vstr &cave, int height)
{
    for (int i = cave[0].size() - 1; i >= 0; i--)
    {
        if (cave[cave.size() - height][i] == 'x')
        {
            cave[cave.size() - height][i] = '.';
            return;
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
    vstr cave(R);
    for (int i = 0; i < R; i++)
    {
        cin >> cave[i];
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int height;
        cin >> height;
        if (i % 2 == 0)
        {
            breakleft(cave, height);
        }
        else
        {
            breakright(cave, height);
        }

        gravity(cave);
    }

    for (auto &&i : cave)
    {
        cout << i << "\n";
    }

    return 0;
}