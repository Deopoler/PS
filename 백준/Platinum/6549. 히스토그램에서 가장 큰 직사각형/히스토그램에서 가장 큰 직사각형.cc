#include <bits/stdc++.h>

using namespace std;
using vll = vector<long long>;
using ll = long long;

ll solve(const vll &histogram, int start, int end)
{
    // [start, end] 범위

    // 기저사례: 밑변이 1이면 높이 리턴
    if (start == end)
        return histogram[start];

    int mid = (start + end) / 2;
    ll ret = max(solve(histogram, start, mid), solve(histogram, mid + 1, end)); // 겹치지 않는 경우 계산

    // 겹치는 경우 계산
    int lo = mid, hi = mid + 1;
    ll height = min(histogram[lo], histogram[hi]);
    ret = max(ret, height * (hi - lo + 1LL));
    while (start < lo || hi < end)
    {
        if (start < lo && (hi == end || histogram[lo - 1] > histogram[hi + 1]))
        {
            lo--;
            height = min(height, histogram[lo]);
        }
        else
        {
            hi++;
            height = min(height, histogram[hi]);
        }

        ret = max(ret, height * (hi - lo + 1LL));
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    while (1)
    {
        cin >> n;
        if (n == 0)
            return 0;

        vll histogram(n);
        for (int i = 0; i < n; i++)
        {
            cin >> histogram[i];
        }

        cout << solve(histogram, 0, histogram.size() - 1) << "\n";
    }

    return 0;
}