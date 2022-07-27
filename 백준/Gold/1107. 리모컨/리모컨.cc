#include <bits/stdc++.h>

using namespace std;

int min_value = INT_MAX;

void bfs(vector<bool> &visited, int start, int target, unordered_set<int> &broken)
{
    queue<pair<int, int>> q;
    q.push({start, 0});

    while (!q.empty())
    {
        auto [node, distance] = q.front();
        q.pop();
        // 노드 처리
        vector<int> nexts;
        for (int i = 0; i < 10; i++)
        {
            if (broken.find(i) == broken.end())
                nexts.push_back(node * 10 + i);
        }
        for (auto &&next : nexts)
        {
            if (next >= 1000000)
                continue;
            if (visited[next])
                continue;

            visited[next] = true;
            min_value = min(min_value, distance + 1 + abs(target - next));
            q.push({next, distance + 1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    int M;
    cin >> M;
    unordered_set<int> broken;
    vector<bool> visited(1000000, false);
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        broken.insert(a);
    }
    min_value = abs(N - 100);
    bfs(visited, 0, N, broken);
    cout << min_value << "\n";
    return 0;
}