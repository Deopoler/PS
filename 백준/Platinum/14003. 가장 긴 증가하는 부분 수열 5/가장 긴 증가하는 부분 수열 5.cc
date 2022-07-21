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
    vector<int> index(N);
    int length = 1;
    arr.push_back(A[0]);

    for (int i = 1; i < N; i++)
    {
        if (A[i] > arr.back())
        {
            arr.push_back(A[i]);
            index[i] = length;
            length += 1;
        }
        else
        {
            int search = lower_bound(arr.begin(), arr.end(), A[i]) - arr.begin();
            index[i] = search;
            arr[search] = A[i];
        }
    }

    cout << length << "\n";

    vector<int> result;
    for (auto i = index.rbegin(); i != index.rend(); i++)
    {
        if (*i == length - 1)
        {
            result.push_back(A[index.rend() - i - 1]);
            length--;
        }
    }

    for (auto i = result.rbegin(); i != result.rend(); i++)
    {
        cout << *i << " ";
    }

    return 0;
}