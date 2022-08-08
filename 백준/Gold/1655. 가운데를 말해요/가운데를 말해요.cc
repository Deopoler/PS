#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (small.empty() || x < small.top())
        {
            small.push(x);
            if (small.size() > big.size() + 1)
            {
                int n = small.top();
                small.pop();
                big.push(n);
            }
        }
        else
        {
            big.push(x);
            if (big.size() > small.size())
            {
                int n = big.top();
                big.pop();
                small.push(n);
            }
        }

        cout << small.top() << "\n";
    }

    return 0;
}