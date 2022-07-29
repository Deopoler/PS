#include <bits/stdc++.h>

using namespace std;

using vvi = vector<vector<int>>;

int dp[100001];

int dfs(vvi &tree, int node, int e)
{
    int count = 0;
    for (auto n : tree[node])
    {
        if (n == e)
            continue;
        count += dfs(tree, n, node);
    }
    dp[node] = count + 1;
    return dp[node];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, r, q;
    cin >> n >> r >> q;

    vvi tree(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(tree, r, -1);

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        cout << dp[x] << "\n";
    }

    return 0;
}