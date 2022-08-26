#include <bits/stdc++.h>

using namespace std;

/* Macros */
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
#define eps 1e-9

/* Types Alias */
using ll = long long;
using ull = unsigned long long;
#define v vector
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

template <typename T,
          T (*op)(T, T)>
class SegTree
{
private:
    int n;
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
        // 범위를 벗어나면 0반환
        if (right < nodeLeft || nodeRight < left)
            return {0, 0};

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
    SegTree(const vector<T> &array)
    {
        n = array.size();
        int height = (int)ceil(log2(n));
        tree.resize(1 << (height + 1));
        init(array, 1, 0, n - 1);
    }

    SegTree(int n, T val = 0) : SegTree(vector<T>(n, val)) {}

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

pair<int, int> op(pair<int, int> a, pair<int, int> b)
{
    int temp[4];
    temp[0] = a.first;
    temp[1] = a.second;
    temp[2] = b.first;
    temp[3] = b.second;
    sort(temp, temp + 4);
    return {temp[3], temp[2]};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    v<pair<int, int>> array(N);

    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        array[i] = {temp, 0};
    }

    SegTree<pair<int, int>, op> seg(array);

    int M;
    cin >> M;
    int query;
    int a;
    int b;
    while (M--)
    {
        cin >> query >> a >> b;
        if (query == 1)
        {
            seg.update(a - 1, {b, 0});
        }
        else if (query == 2)
        {
            auto result = seg.query(a - 1, b - 1);
            cout << result.first + result.second << "\n";
        }
        else
        {
            assert(false);
        }
    }

    return 0;
}