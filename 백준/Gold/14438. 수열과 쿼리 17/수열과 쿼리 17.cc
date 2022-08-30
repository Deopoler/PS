#include <bits/stdc++.h>

using namespace std;

/* Macros */
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define eps 1e-9
constexpr int inf = numeric_limits<int>::max() / 2;
constexpr long long llinf = numeric_limits<long long>::max() / 2;

/* Types Aliases */
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define umap unordered_map
#define uset unordered_set
#define ummap unordered_multimap
#define umset unordered_multiset
#define mmap multimap
#define mset multiset

/* Utils */
template <typename T>
struct reversion_wrapper
{
    T &iterable;
};

template <typename T>
auto begin(reversion_wrapper<T> w) { return std::rbegin(w.iterable); }

template <typename T>
auto end(reversion_wrapper<T> w) { return std::rend(w.iterable); }

template <typename T>
reversion_wrapper<T> reversed(T &&iterable) { return {iterable}; }
/* End Template */

template <typename T,
          T (*op)(T &, T &)>
class SegTree
{
private:
    int n;
    T val;
    vector<T> tree;

    // node가 [nodeLeft..nodeRight] 표현
    // node를 루트로 하는 서브트리 초기화
    T init(const vector<T> &array, int node, int nodeLeft, int nodeRight)
    {
        if (nodeLeft == nodeRight)
            return tree[node] = array[nodeLeft];
        int mid = (nodeLeft + nodeRight) / 2;
        T leftValue = init(array, node * 2, nodeLeft, mid);
        T rightValue = init(array, node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = op(leftValue, rightValue);
    }

    // node가 [nodeLeft..nodeRight] 표현
    // array[left..right]의 값 반환
    T query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        // 범위를 벗어나면 기본값반환
        if (right < nodeLeft || nodeRight < left)
            return val;

        if (left <= nodeLeft && nodeRight <= right)
            return tree[node];

        int mid = (nodeLeft + nodeRight) / 2;
        T leftValue = query(left, right, node * 2, nodeLeft, mid);
        T rightValue = query(left, right, node * 2 + 1, mid + 1, nodeRight);
        return op(leftValue, rightValue);
    }

    // array[index] = newValue로 변경
    // node가 [nodeLeft..nodeRight] 표현
    // array[nodeLeft..nodeRight]의 값 반환
    T update(int index, T newValue, int node, int nodeLeft, int nodeRight)
    {
        // 범위를 벗어나면 원래 값 반환
        if (index < nodeLeft || nodeRight < index)
            return tree[node];

        // 리프노드이면 값 변경
        if (nodeLeft == nodeRight)
            return tree[node] = newValue;

        int mid = (nodeLeft + nodeRight) / 2;
        T leftValue = update(index, newValue, node * 2, nodeLeft, mid);
        T rightValue = update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = op(leftValue, rightValue);
    }

public:
    SegTree(const vector<T> &array, T val)
    {
        n = array.size();
        this->val = val;
        int height = (int)ceil(log2(n));
        tree.resize(1 << (height + 1));
        init(array, 1, 0, n - 1);
    }

    SegTree(int n, T val) : SegTree(vector<T>(n, val), val) {}

    // array[left..right] 값 반환
    T query(int left, int right)
    {
        return query(left, right, 1, 0, n - 1);
    }

    // array[index] = newValue로 변경
    T update(int index, T newValue)
    {
        return update(index, newValue, 1, 0, n - 1);
    }
};

int oper(int &a, int &b)
{
    return min(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    for (auto &i : A)
    {
        cin >> i;
    }

    SegTree<int, oper> seg(A, inf);

    int M;
    cin >> M;

    int query, a, b;
    while (M--)
    {
        cin >> query >> a >> b;
        if (query == 1)
        {
            seg.update(a - 1, b);
        }
        else if (query == 2)
        {
            cout << seg.query(a - 1, b - 1) << "\n";
        }
        else
        {
            assert(false);
        }
    }

    return 0;
}