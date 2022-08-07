#include <bits/stdc++.h>

using namespace std;

bool same(int *begin, int *end)
{
    int temp = *begin;
    for (; begin != end; ++begin)
    {
        if (*begin != temp)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int nums[N];
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    if (N == 1)
    {
        cout << "A\n";
    }
    else
    {
        if (nums[0] == nums[1])
        {
            if (same(nums, nums + N))
            {
                cout << nums[0] << "\n";
            }
            else
            {
                cout << "B\n";
            }
        }
        else if (N == 2)
        {
            cout << "A\n";
        }
        else
        {
            if ((nums[2] - nums[1]) % (nums[1] - nums[0]) != 0)
            {
                cout << "B\n";
            }
            else
            {
                bool isB = false;
                int a = (nums[2] - nums[1]) / (nums[1] - nums[0]);
                int b = nums[1] - nums[0] * a;
                for (int i = 1; i < N - 1; i++)
                {
                    if (a * nums[i] + b != nums[i + 1])
                        isB = true;
                }
                if (isB)
                {
                    cout << "B\n";
                }
                else
                {
                    cout << a * nums[N - 1] + b << "\n";
                }
            }
        }
    }

    return 0;
}