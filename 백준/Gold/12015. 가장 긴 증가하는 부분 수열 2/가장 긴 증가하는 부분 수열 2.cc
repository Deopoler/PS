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

    vector<int> arr;
    int length = 1;
    arr.push_back(A[0]);

    for (int i = 1; i < N; i++)
    {
        if (A[i] > arr.back())
        {
            arr.push_back(A[i]);
            length += 1;
        }
        else
        {
            arr[lower_bound(arr.begin(), arr.end(), A[i]) - arr.begin()] = A[i];
        }
    }

    cout << length << "\n";

    return 0;
}