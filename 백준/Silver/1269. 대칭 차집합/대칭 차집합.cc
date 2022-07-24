#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    set<int> A;
    set<int> B;

    for (int i = 0; i < a; i++)
    {
        int n;
        cin >> n;
        A.insert(n);
    }

    for (int i = 0; i < b; i++)
    {
        int n;
        cin >> n;
        B.insert(n);
    }
    int sum;
    set<int> result;
    set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(result, result.end()));
    sum = result.size();

    result.clear();
    set_difference(B.begin(), B.end(), A.begin(), A.end(), inserter(result, result.end()));
    sum += result.size();

    cout << sum << "\n";

    return 0;
}