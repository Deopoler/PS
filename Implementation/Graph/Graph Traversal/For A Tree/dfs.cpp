#include <bits/stdc++.h>
using namespace std;

using Tree = vector<vector<int>>;

void dfs(Tree &tree, int node, int e)
{
    for (auto n : tree[node])
    {
        if (n == e)
            continue;
        dfs(tree, n, node);
    }
}