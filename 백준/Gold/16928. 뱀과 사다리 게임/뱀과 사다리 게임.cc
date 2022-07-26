#include <bits/stdc++.h>

using namespace std;

int bfs(int start, int target, vector<bool> &visited, const vector<pair<int, int>> &l)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty())
    {
        auto [node, distance] = q.front();
        q.pop();
        // 노드 처리

        for (int next = node + 1; next < node + 7; next++)
        {
            if (next == target)
                return distance + 1;
            if (next > target)
                continue;
            int temp = next;
            for (auto [a, b] : l)
            {
                if (a == temp)
                    temp = b;
            }

            if (visited[temp])
                continue;

            visited[temp] = true;
            q.push({temp, distance + 1});
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

    vector<pair<int, int>> l(N + M);
    vector<bool> visited(101);
    for (int i = 0; i < N + M; i++)
    {
        int a, b;
        cin >> a >> b;
        l[i] = {a, b};
    }

    auto result = bfs(1, 100, visited, l);

    cout << result << "\n";

    return 0;
}