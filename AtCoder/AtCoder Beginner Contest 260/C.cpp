#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, X, Y;
    cin >> N >> X >> Y;

    long long red[11] = {0};
    long long blue[11] = {0};

    red[N] = 1;

    for (int i = N; i > 1; i--)
    {
        blue[i] += red[i] * X;
        red[i - 1] += red[i];
        red[i] = 0;

        red[i - 1] += blue[i];
        blue[i - 1] += blue[i] * Y;
        blue[i] = 0;
    }

    cout << blue[1];

    return 0;
}