#include <bits/stdc++.h>

#define MAX 16

using namespace std;

int cache[MAX][1 << MAX];
int dist[MAX][MAX];
int N;

int shortestPath(int current, int visited)
{
    int &ret = cache[current][visited];
    if (ret != -1)
        return ret;

    if (visited == (1 << N) - 1)
        return ret = dist[current][0];

    ret = INT_MAX;
    for (int next = 0; next < N; next++)
    {
        if (visited & (1 << next))
            continue;
        ret = min(ret, dist[current][next] + shortestPath(next, visited | (1 << next)));
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int w;
            cin >> w;
            if (w == 0)
                dist[i][j] = 987654321; // INF
            else
                dist[i][j] = w;
        }
    }
    memset(cache, -1, sizeof(cache));

    cout << shortestPath(0, 1) << "\n";

    return 0;
}