#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n, m;
    vector<int> a, c;

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    cin >> m;
    c.resize(m);
    for (int i = 0; i < m; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++)
        cout << binary_search(a.begin(), a.end(), c[i]) << "\n";
}