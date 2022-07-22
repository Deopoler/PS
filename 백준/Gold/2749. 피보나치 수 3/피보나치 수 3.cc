#include <bits/stdc++.h>
#define MOD 1000000

using namespace std;

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Matrix
{
public:
    vector<vector<T>> m;

    Matrix(vector<vector<T>> data)
    {
        m = data;
    }

    Matrix(long long row, long long column)
    {
        m.assign(row, vector<T>(column, 0));
    }

    Matrix(const Matrix &data)
    {
        m = data.m;
    }

    Matrix
    operator+(const Matrix &a)
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

    Matrix operator+(T a)
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

    Matrix operator-(T a)
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

    Matrix operator*(T a)
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

    Matrix operator/(T a)
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

    Matrix operator%(T a)
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

    vector<T> operator[](int index)
    {
        return m[index];
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

template <typename T>
Matrix<T> pow(Matrix<T> A, long long N, long long mod)
{
    if (N == 1)
        return A % mod;

    Matrix<T> B = pow(A, N / 2, mod);

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

    long long N;
    cin >> N;

    Matrix<long long> A(vector<vector<long long>>{{1, 1}, {1, 0}});

    auto B = pow(A, N, MOD);
    cout << B[1][0] << "\n";

    return 0;
}