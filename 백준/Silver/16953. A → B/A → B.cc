#include <bits/stdc++.h>

using namespace std;

long long bfs(int start, int max)
{
    queue<pair<long long, long long>> q;
    q.push({start, 0LL});

    while (!q.empty())
    {
        auto [node, distance] = q.front();
        q.pop();
        // 노드 처리
        for (auto &&next : {node * 2, node * 10 + 1})
        {
            if (next == max)
                return distance + 1;
            if (next > max)
                continue;
            q.push({next, distance + 1});
        }
    }
    return -2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B;
    cin >> A >> B;

    auto distance = bfs(A, B);

    cout << distance + 1 << "\n";

    return 0;
}