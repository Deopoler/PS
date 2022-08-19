#include <bits/stdc++.h>

#define MAX 101
#define MOD 1000000000
using namespace std;

int cache[MAX][1 << 10][10];

int N;

// current번째까지 used를 사용했고, 마지막 숫자가 last일때 계단 수의 개수
int solve(int current, int used, int last)
{
    if (cache[current][used][last] != -1)
        return cache[current][used][last];

    int &ret = cache[current][used][last];

    if (N == current)
    {
        if (used == (1 << 10) - 1)
            return ret = 1; // 모두 사용했으면
        return ret = 0;
    }

    ret = 0; // 최소 0개

    if (last > 0)
        ret += solve(current + 1, used | (1 << (last - 1)), last - 1);
    ret %= MOD;
    if (last < 9)
        ret += solve(current + 1, used | (1 << (last + 1)), last + 1);
    ret %= MOD;

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    int result = 0;
    memset(cache, -1, sizeof(cache));
    for (int i = 1; i < 10; i++)
    {
        result += solve(1, (1 << i), i);
        result %= MOD;
    }

    cout << result << "\n";

    return 0;
}