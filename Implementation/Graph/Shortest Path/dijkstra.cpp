#include <bits/stdc++.h>
using namespace std;
#define llinf (numeric_limits<long long>::max() / 4)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())

// 인접리스트 구현
using ll = long long;
using vvil = vector<vector<pair<int, long long>>>;
using vll = vector<long long>;
void dijkstra(vvil &graph, vll &distance, int start)
{
    priority_queue<pair<ll, int>> q;

    distance[start] = 0;
    q.push({0, start});
    while (!q.empty())
    {
        int node = q.top().second;
        q.pop();
        for (auto [next, w] : graph[node])
        {
            if (distance[node] + w < distance[next])
            {
                distance[next] = distance[node] + w;
                q.push({-distance[next], next}); // c++ priority queue는 최대 힙이기 때문에 거리에 -를 붙임
            }
        }
    }
}

// 인접행렬 구현
using ll = long long;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
void dijkstra(vvll &graph, vll &distance, int start)
{
    vector<bool> visited(graph.size(), false);
    visited[start] = true;
    for (int i = 0; i < sz(graph); i++)
    {
        distance[i] = graph[start][i];
    }

    int n = sz(graph);
    while (n--)
    {
        int current = 0;
        int min = llinf;
        for (int i = 0; i < sz(graph); i++) // 최소비용 노드 찾기
        {
            if (distance[i] < min && !visited[i])
            {
                min = distance[i];
                current = i;
            }
        }
        visited[current] = true;

        for (int i = 0; i < sz(graph); i++)
        {
            if (!visited[i])
            {
                if (distance[current] + graph[current][i] < distance[i])
                {
                    distance[i] = distance[current] + graph[current][i];
                }
            }
        }
    }
}