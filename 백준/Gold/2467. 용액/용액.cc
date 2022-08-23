#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    auto start = A.begin();
    auto end = A.end() - 1;

    int best_value = INT_MAX;
    pair<int, int> best;

    while (start != end)
    {
        if (abs(*start + *end) < best_value)
        {
            best_value = abs(*start + *end);
            best = {*start, *end};
        }
        if (*start + *end < 0)
        {
            start++;
        }
        else if (*start + *end > 0)
        {
            end--;
        }
        else
        {
            best = {*start, *end};
            break;
        }
    }

    cout << best.first << " " << best.second << "\n";

    return 0;
}