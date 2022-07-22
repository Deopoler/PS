#include <bits/stdc++.h>

using namespace std;

class Matrix
{
public:
    vector<vector<int>> m;

    Matrix(vector<vector<int>> data)
    {
        m = data;
    }

    Matrix(int row, int column)
    {
        m.assign(row, vector<int>(column, 0));
    }

    Matrix operator+(const Matrix &a)
    {
        Matrix b = Matrix(m.size(), m[0].size());
        for (int i = 0; i < m.size(); i++)
        {
            for (int j = 0; j < m[0].size(); j++)
            {
                b.m[i][j] = m[i][j] + a.m[i][j];
            }
        }
        return b;
    }

    Matrix operator-(const Matrix &a)
    {
        Matrix b = Matrix(m.size(), m[0].size());
        for (int i = 0; i < m.size(); i++)
        {
            for (int j = 0; j < m[0].size(); j++)
            {
                b.m[i][j] = m[i][j] - a.m[i][j];
            }
        }
        return b;
    }

    Matrix operator*(const Matrix &a)
    {
        Matrix b = Matrix(m.size(), a.m[0].size());
        for (int i = 0; i < m.size(); i++)
        {
            for (int j = 0; j < a.m[0].size(); j++)
            {
                for (int k = 0; k < m[0].size(); k++)
                {
                    b.m[i][j] += m[i][k] * a.m[k][j];
                }
            }
        }
        return b;
    }

    void showMatrix()
    {
        for (auto &&i : m)
        {
            for (auto &&j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M;
    vector<vector<int>> a(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> M >> K;
    vector<vector<int>> b(M, vector<int>(K));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            cin >> b[i][j];
        }
    }

    Matrix A(a);
    Matrix B(b);

    (A * B).showMatrix();

    return 0;
}