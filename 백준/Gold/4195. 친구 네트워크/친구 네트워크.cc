#include <bits/stdc++.h>

using namespace std;

class Union_Find
{
private:
    int *link;
    long long *size;

public:
    Union_Find(int n)
    {
        link = new int[n];
        size = new long long[n];
        for (int i = 0; i < n; i++)
        {
            link[i] = i;
            size[i] = 1LL;
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
        if (find(a) == find(b))
            return;
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

    long long getsize(int x)
    {
        return size[find(x)];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        Union_Find uf(200000);
        unordered_map<string, int> index;
        for (int i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;
            if (index.find(a) == index.end())
            {
                index[a] = index.size();
            }
            if (index.find(b) == index.end())
            {
                index[b] = index.size();
            }

            int c = index[a];
            int d = index[b];
            uf.unite(c, d);

            cout << uf.getsize(c) << "\n";
        }
    }
    return 0;
}