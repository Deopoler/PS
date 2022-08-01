#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int arr[100000];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int result_a = -1;
    int result_b = -1;
    int result_value = INT_MAX;
    int right = n - 1;
    int left = 0;
    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (abs(sum) < result_value)
        {
            result_a = left;
            result_b = right;
            result_value = abs(sum);
        }
        if (sum > 0)
        {
            right--;
        }
        else if (sum < 0)
        {
            left++;
        }
        else
        {
            break;
        }
    }
    cout << arr[result_a] << " " << arr[result_b] << "\n";

    return 0;
}