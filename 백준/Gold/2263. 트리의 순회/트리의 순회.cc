#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve(int i_start, int i_end, vi &in_order, int p_start, int p_end, vi &post_order)
{
    if (i_start >= i_end)
        return;
    int root = post_order[p_end - 1];
    cout << root << " ";

    int root_index = find(in_order.begin() + i_start, in_order.begin() + i_end, root) - in_order.begin();

    solve(i_start, root_index, in_order, p_start, p_start + root_index - i_start, post_order);
    solve(root_index + 1, i_end, in_order, p_start + root_index - i_start, p_end - 1, post_order);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vi in_order(n);
    vi post_order(n);
    for (int i = 0; i < n; i++)
    {
        cin >> in_order[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> post_order[i];
    }
    solve(0, n, in_order, 0, n, post_order);
    return 0;
}