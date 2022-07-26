#include <bits/stdc++.h>

using namespace std;

string bfs(int start, int target, vector<bool> &visited)
{
    queue<pair<int, string>> q;
    q.push({start, ""});
    visited[start] = true;

    while (!q.empty())
    {
        auto [node, commands] = q.front();
        q.pop();
        // 노드 처리
        pair<int, string> a[4] = {
            {2 * node % 10000, "D"},
            {(node - 1 + 10000) % 10000, "S"},
            {(node * 10 % 10000) + node / 1000, "L"},
            {(node % 10) * 1000 + (node / 10), "R"}};
        for (auto [next, com] : a)
        {
            {
                if (next == target)
                {
                    return commands + com;
                }
                if (visited[next])
                    continue;

                visited[next] = true;
                q.push({next, commands + com});
            }
        }
    }
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
        int N, M;
        cin >> N >> M;

        vector<bool> visited(10001);

        auto result = bfs(N, M, visited);
        cout << result << "\n";
    }

    return 0;
}