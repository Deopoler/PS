#include <bits/stdc++.h>
#define MOD 1000

using namespace std;

class Matrix
{
public:
    vector<vector<long long>> m;

    Matrix(vector<vector<long long>> data)
    {
        m = data;
    }

    Matrix(long long row, long long column)
    {
        m.assign(row, vector<long long>(column, 0));
    }

    Matrix operator+(const Matrix &a)
    {
        Matrix b = Matrix(m.size(), m[0].size());
        for (long long i = 0; i < m.size(); i++)
        {
            for (long long j = 0; j < m[0].size(); j++)
            {
                b.m[i][j] = m[i][j] + a.m[i][j];
            }
        }
        return b;
    }

    Matrix operator+(long long a)
    {
        Matrix b = Matrix(m.size(), m[0].size());
        for (long long i = 0; i < m.size(); i++)
        {
            for (long long j = 0; j < m[0].size(); j++)
            {
                b.m[i][j] = m[i][j] + a;
            }
        }
        return b;
    }

    Matrix operator-(const Matrix &a)
    {
        Matrix b = Matrix(m.size(), m[0].size());
        for (long long i = 0; i < m.size(); i++)
        {
            for (long long j = 0; j < m[0].size(); j++)
            {
                b.m[i][j] = m[i][j] - a.m[i][j];
            }
        }
        return b;
    }

    Matrix operator-(long long a)
    {
        Matrix b = Matrix(m.size(), m[0].size());
        for (long long i = 0; i < m.size(); i++)
        {
            for (long long j = 0; j < m[0].size(); j++)
            {
                b.m[i][j] = m[i][j] - a;
            }
        }
        return b;
    }

    Matrix operator*(const Matrix &a)
    {
        Matrix b = Matrix(m.size(), a.m[0].size());
        for (long long i = 0; i < m.size(); i++)
        {
            for (long long j = 0; j < a.m[0].size(); j++)
            {
                for (long long k = 0; k < m[0].size(); k++)
                {
                    b.m[i][j] += m[i][k] * a.m[k][j];
                }
            }
        }
        return b;
    }

    Matrix operator*(long long a)
    {
        Matrix b = Matrix(m.size(), m[0].size());
        for (long long i = 0; i < m.size(); i++)
        {
            for (long long j = 0; j < m[0].size(); j++)
            {
                b.m[i][j] = m[i][j] * a;
            }
        }
        return b;
    }

    Matrix operator/(long long a)
    {
        Matrix b = Matrix(m.size(), m[0].size());
        for (long long i = 0; i < m.size(); i++)
        {
            for (long long j = 0; j < m[0].size(); j++)
            {
                b.m[i][j] = m[i][j] / a;
            }
        }
        return b;
    }

    Matrix operator%(long long a)
    {
        Matrix b = Matrix(m.size(), m[0].size());
        for (long long i = 0; i < m.size(); i++)
        {
            for (long long j = 0; j < m[0].size(); j++)
            {
                b.m[i][j] = m[i][j] % a;
            }
        }
        return b;
    }

    bool operator==(const Matrix &a)
    {
        for (long long i = 0; i < m.size(); i++)
        {
            for (long long j = 0; j < m[0].size(); j++)
            {
                if (m[i][j] != a.m[i][j])
                    return false;
            }
        }
        return true;
    }

    void showMatrixPretty()
    {
        for (auto &&i : m)
        {
            for (auto &&j : i)
            {
                cout << setw(4) << j;
            }
            cout << "\n";
        }
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

    ~Matrix()
    {
        m.clear();
        m.shrink_to_fit();
    }
};

Matrix pow(Matrix A, long long N, long long mod)
{
    if (N == 1)
        return A % mod;

    Matrix B = pow(A, N / 2, mod);

    if (N % 2 == 1)
    {
        return (B * B * A) % mod;
    }
    else
    {
        return (B * B) % mod;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N, B;
    cin >> N >> B;
    vector<vector<long long>> a(N, vector<long long>(N));
    for (long long i = 0; i < N; i++)
    {
        for (long long j = 0; j < N; j++)
        {
            cin >> a[i][j];
        }
    }

    Matrix A(a);

    pow(A, B, MOD).showMatrix();

    return 0;
}