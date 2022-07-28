#include <bits/stdc++.h>
using namespace std;

using vvi = vector<vector<int>>;

void dfs(vvi &tree, int node, int e)
{
    for (auto n : tree[node])
    {
        if (n == e)
            continue;
        dfs(tree, n, node);
    }
}