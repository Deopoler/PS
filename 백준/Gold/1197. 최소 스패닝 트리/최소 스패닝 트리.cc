#include <bits/stdc++.h>

using namespace std;

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
        a = find(a);
        b = find(b);
        if (size[a] < size[b])
            swap(a, b);
        size[a] += size[b];
        link[b] = a;
    }

    bool same(int a, int b)
    {
        return find(a) == find(b);
    }
};

int kruskal(vector<tuple<int, int, int>> &graph, int nodes)
{
    int result = 0;
    sort(
        graph.begin(), graph.end(), [](const auto &a, const auto &b)
        { return get<2>(a) < get<2>(b); });
    Union_Find uf(nodes + 1);
    for (auto [a, b, w] : graph)
    {
        if (!uf.same(a, b))
        {
            result += w;
            uf.unite(a, b);
        }
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int V, E;
    cin >> V >> E;
    vector<tuple<int, int, int>> graph;
    for (int i = 0; i < E; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph.push_back({a, b, w});
    }

    cout << kruskal(graph, V) << "\n";

    return 0;
}