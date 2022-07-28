#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;

    sort(arr, arr + n);

    int j = n - 1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        while (arr[i] + arr[j] > x)
        {
            j--;
        }

        if (i >= j)
            break;

        if (arr[i] + arr[j] == x)
        {
            count++;
        }
    }
    cout << count << "\n";

    return 0;
}