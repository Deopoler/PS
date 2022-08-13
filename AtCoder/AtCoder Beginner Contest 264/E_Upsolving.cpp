#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#include <bits/stdc++.h>

using namespace std;

class Union_Find
{
private:
    int *link;
    int *size;
    int N;
    int M;

public:
    Union_Find(int N, int M)
    {
        link = new int[N + M + 1];
        size = new int[N + M + 1];
        for (int i = 0; i < N + M + 1; i++)
        {
            link[i] = i;
            size[i] = 1;
        }
        this->N = N;
        this->M = M;
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
        if (a == b)
            return;
        if (b > N)
            swap(a, b);
        size[a] += size[b];
        link[b] = a;
    }

    bool same(int a, int b)
    {
        return find(a) == find(b);
    }

    int getsize(int x)
    {
        return size[find(x)];
    }

    bool iselectrified(int pos)
    {
        return find(pos) > N;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, E;
    cin >> N >> M >> E;
    Union_Find uf(N, M);

    vector<pair<int, int>> edges(E + 1);
    for (int i = 1; i <= E; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    int Q;
    cin >> Q;
    vector<int> events(Q);
    unordered_set<int> events_set;
    for (int i = 0; i < Q; i++)
    {
        cin >> events[i];
        events_set.insert(events[i]);
    }

    int count = 0;
    for (int i = 1; i <= E; i++)
    {
        if (events_set.find(i) == events_set.end())
        {
            bool first = uf.iselectrified(edges[i].first);
            int first_size = uf.getsize(edges[i].first);
            bool second = uf.iselectrified(edges[i].second);
            int second_size = uf.getsize(edges[i].second);
            uf.unite(edges[i].first, edges[i].second);
            if (!first)
            {
                if (uf.iselectrified(edges[i].first))
                {
                    count += first_size;
                }
            }
            if (!second)
            {
                if (uf.iselectrified(edges[i].second))
                {
                    count += second_size;
                }
            }
        }
    }
    vector<int> result;
    result.push_back(count);
    // for (int i = 1; i < N + M + 1; i++)
    // {
    //     cout << uf.iselectrified(i) << " ";
    // }
    // cout << "\n";

    for (auto i = events.rbegin(); i != events.rend(); i++)
    {
        bool first = uf.iselectrified(edges[*i].first);
        int first_size = uf.getsize(edges[*i].first);
        bool second = uf.iselectrified(edges[*i].second);
        int second_size = uf.getsize(edges[*i].second);
        int current = result.back();
        uf.unite(edges[*i].first, edges[*i].second);
        if (!first && uf.iselectrified(edges[*i].first))
        {
            current += first_size;
        }
        if (!second && uf.iselectrified(edges[*i].second))
        {
            current += second_size;
        }
        // for (int i = 1; i < N + M + 1; i++)
        // {
        //     cout << uf.iselectrified(i) << " ";
        // }
        // cout << "\n";

        result.push_back(current);
    }

    for (auto i = result.rbegin() + 1; i != result.rend(); i++)
    {
        cout << *i << "\n";
    }

    return 0;
}