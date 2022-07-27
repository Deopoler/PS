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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Union_Find uf(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
            {
                uf.unite(i, j);
            }
        }
    }

    bool result = true;
    int previous;
    cin >> previous;
    for (int i = 0; i < m - 1; i++)
    {
        int temp;
        cin >> temp;
        result &= uf.same(previous, temp);
        previous = temp;
    }

    if (result)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}