#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int g = nums[1] - nums[0];
    for (int i = 1; i < N - 1; i++)
    {
        g = gcd(g, nums[i + 1] - nums[i]);
    }

    vector<int> result_a;
    vector<int> result_b;
    for (int i = 2; i <= sqrt(g); i++)
    {
        if (g % i == 0)
        {
            result_a.push_back(i);
            if (i != sqrt(g))
            {
                result_b.push_back(g / i);
            }
        }
    }

    for (auto &&i : result_a)
    {
        cout << i << " ";
    }
    for (auto i = result_b.rbegin(); i < result_b.rend(); i++)
    {
        cout << *i << " ";
    }
    cout << g << "\n";
}