#include <bits/stdc++.h>
using namespace std;

vector<int> dist(200001, 1e9);

void bfs(int start)
{
    deque<int> q;
    dist[start] = 0;
    q.push_back(start);
    while (!q.empty())
    {
        int node = q.front();
        q.pop_front();

        int next = node * 2;
        if (next <= 200000 && dist[next] > dist[node])
        {
            dist[next] = dist[node];
            q.push_front(next);
        }

        next = node - 1;
        if (next >= 0 && dist[next] > dist[node] + 1)
        {
            dist[next] = dist[node] + 1;
            q.push_back(next);
        }

        next = node + 1;
        if (next <= 200000 && dist[next] > dist[node] + 1)
        {
            dist[next] = dist[node] + 1;
            q.push_back(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    bfs(N);

    cout << dist[K] << "\n";

    return 0;
}