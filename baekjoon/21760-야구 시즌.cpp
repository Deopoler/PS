#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, M, k, D;
        cin >> N >> M >> k >> D;
        int B = (2 * D) / (N * M * ((N - 1) * M + (M - 1) * k));
        if (B == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << (N * M * B * ((N - 1) * M + (M - 1) * k)) / 2 << "\n";
        }
    }
}