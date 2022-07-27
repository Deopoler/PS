#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<pair<int, int>>> &graph, vector<int> &distance, int start)
{
    deque<int> q;
    q.push_back(start);
    distance[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop_front();
        for (auto [next, w] : graph[node])
        {
            if (distance[node] + w < distance[next])
            {
                if (w == 1)
                {
                    distance[next] = distance[node] + 1;
                    q.push_back(next);
                }
                else
                {
                    distance[next] = distance[node];
                    q.push_front(next);
                }
            }
        }
    }
}