#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int N;
int W;
int cache[MAX][MAX];
pair<int, int> pitch[MAX];

// (1,1)에서 시작한 경찰차가 마지막으로 a, (N,N)에서 시작한 경찰차가 마지막으로 b를 처리했을때의 최솟값
int solve(int a, int b)
{
    if (cache[a][b] != -1)
        return cache[a][b];

    int &ret = cache[a][b];
    if (a == W || b == W)
        return ret = 0;

    int next = max(a, b) + 1;

    ret = INT_MAX;
    if (a == 0)
    {
        ret = min(ret, solve(next, b) + abs(1 - pitch[next].first) + abs(1 - pitch[next].second));
    }
    else
    {
        ret = min(ret, solve(next, b) + abs(pitch[a].first - pitch[next].first) + abs(pitch[a].second - pitch[next].second));
    }
    if (b == 0)
    {
        ret = min(ret, solve(a, next) + abs(N - pitch[next].first) + abs(N - pitch[next].second));
    }
    else
    {
        ret = min(ret, solve(a, next) + abs(pitch[b].first - pitch[next].first) + abs(pitch[b].second - pitch[next].second));
    }

    return ret;
}

void reconstuct(int a, int b, vector<int> &path)
{
    if (a == W || b == W)
        return;
    int next = max(a, b) + 1;

    int A;
    int B;

    if (a == 0)
    {
        A = solve(next, b) + abs(1 - pitch[next].first) + abs(1 - pitch[next].second);
    }
    else
    {
        A = solve(next, b) + abs(pitch[a].first - pitch[next].first) + abs(pitch[a].second - pitch[next].second);
    }
    if (b == 0)
    {
        B = solve(a, next) + abs(N - pitch[next].first) + abs(N - pitch[next].second);
    }
    else
    {
        B = solve(a, next) + abs(pitch[b].first - pitch[next].first) + abs(pitch[b].second - pitch[next].second);
    }

    if (A < B)
    {
        path.push_back(1);
        reconstuct(next, b, path);
    }
    else
    {
        path.push_back(2);
        reconstuct(a, next, path);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cin >> W;
    memset(cache, -1, sizeof(cache));

    for (int i = 1; i <= W; i++)
    {
        int row, col;
        cin >> row >> col;
        pitch[i] = {row, col};
    }

    cout << solve(0, 0) << "\n";

    vector<int> path;
    reconstuct(0, 0, path);

    for (auto &&i : path)
    {
        cout << i << "\n";
    }

    return 0;
}