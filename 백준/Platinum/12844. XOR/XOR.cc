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
using ld = long double;
#define umap unordered_map
#define uset unordered_set
#define ummap unordered_multimap
#define umset unordered_multiset
#define mmap multimap
#define mset multiset
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vii = vector<pair<int, int>>;
using vvii = vector<vector<pair<int, int>>>;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

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

template <typename Value, typename Lazy>
struct Node
{
    Value value;
    Lazy lazy;
};

template <typename Value, typename Lazy>
class LazySegTree
{
private:
    int n;
    Value value_identity;
    Lazy lazy_identity;
    vector<Node<Value, Lazy>> tree;

    // 좌측 노드와 우측 노드의 연산 정의
    // 결합법칙을 만족하고 항등원이 존재해야 함
    // 문제마다 수정(기본은 합 연산)
    Value merge(Value &a, Value &b)
    {
        return a ^ b;
    }

    // lazy로 현재 노드의 값 변경
    // 문제마다 수정(기본은 합 연산)
    void lazyUpdate(Lazy &lazy, int node, int nodeLeft, int nodeRight)
    {
        if ((nodeRight - nodeLeft + 1) % 2 == 1)
        {
            tree[node].value ^= lazy;
        }
    }

    // 원래 Lazy와 새로운 Lazy의 연산 정의
    // 문제마다 수정(기본은 합 연산)
    Lazy mergeLazy(Lazy &a, Lazy &b)
    {
        return a ^ b;
    }

    // node가 [nodeLeft..nodeRight] 표현
    // node를 루트로 하는 서브트리 초기화
    Value init(const vector<Value> &array, int node, int nodeLeft, int nodeRight)
    {
        if (nodeLeft == nodeRight)
            return tree[node].value = array[nodeLeft];
        int mid = (nodeLeft + nodeRight) / 2;
        Value leftValue = init(array, node * 2, nodeLeft, mid);
        Value rightValue = init(array, node * 2 + 1, mid + 1, nodeRight);
        tree[node].lazy = lazy_identity;
        return tree[node].value = merge(leftValue, rightValue);
    }

    // node가 [nodeLeft..nodeRight] 표현
    // array[left..right]의 값 반환
    Value query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        if (tree[node].lazy != lazy_identity)
        {
            lazyUpdate(tree[node].lazy, node, nodeLeft, nodeRight);
            if (nodeLeft != nodeRight)
            {
                tree[node * 2].lazy = mergeLazy(tree[node * 2].lazy, tree[node].lazy);
                tree[node * 2 + 1].lazy = mergeLazy(tree[node * 2 + 1].lazy, tree[node].lazy);
            }
            tree[node].lazy = lazy_identity;
        }

        // 범위를 벗어나면 항등원반환
        if (right < nodeLeft || nodeRight < left)
            return value_identity;

        if (left <= nodeLeft && nodeRight <= right)
            return tree[node].value;

        int mid = (nodeLeft + nodeRight) / 2;
        Value leftValue = query(left, right, node * 2, nodeLeft, mid);
        Value rightValue = query(left, right, node * 2 + 1, mid + 1, nodeRight);
        return merge(leftValue, rightValue);
    }

    // array[index] = lazymerge(newValue)로 변경
    // node가 [nodeLeft..nodeRight] 표현
    // array[nodeLeft..nodeRight]의 값 반환
    Value update(int left, int right, Lazy newValue, int node, int nodeLeft, int nodeRight)
    {

        if (tree[node].lazy != lazy_identity)
        {
            lazyUpdate(tree[node].lazy, node, nodeLeft, nodeRight);
            if (nodeLeft != nodeRight)
            {
                tree[node * 2].lazy = mergeLazy(tree[node * 2].lazy, tree[node].lazy);
                tree[node * 2 + 1].lazy = mergeLazy(tree[node * 2 + 1].lazy, tree[node].lazy);
            }
            tree[node].lazy = lazy_identity;
        }
        // 범위를 벗어나면 원래 값 반환
        if (right < nodeLeft || nodeRight < left)
            return tree[node].value;

        if (left <= nodeLeft && nodeRight <= right)
        {
            lazyUpdate(newValue, node, nodeLeft, nodeRight);
            if (nodeLeft != nodeRight)
            {
                tree[node * 2].lazy = mergeLazy(tree[node * 2].lazy, newValue);
                tree[node * 2 + 1].lazy = mergeLazy(tree[node * 2 + 1].lazy, newValue);
            }
            return tree[node].value;
        }

        int mid = (nodeLeft + nodeRight) / 2;
        Value leftValue = update(left, right, newValue, node * 2, nodeLeft, mid);
        Value rightValue = update(left, right, newValue, node * 2 + 1, mid + 1, nodeRight);
        return tree[node].value = merge(leftValue, rightValue);
    }

public:
    LazySegTree(const vector<Value> &array, Value value_identity, Lazy lazy_identity) : value_identity(value_identity), lazy_identity(lazy_identity)
    {
        n = array.size();
        int height = (int)ceil(log2(n));
        tree.resize(1 << (height + 1));
        init(array, 1, 0, n - 1);
    }

    LazySegTree(int n, Value value_identity, Lazy lazy_identity) : LazySegTree(vector<Value>(n, value_identity), value_identity, lazy_identity) {}

    // array[left..right] 값 반환
    Value query(int left, int right)
    {
        return query(left, right, 1, 0, n - 1);
    }

    // array[index] = lazymerge(newValue)로 변경
    Value update(int left, int right, Lazy newValue)
    {
        return update(left, right, newValue, 1, 0, n - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vi A(N);
    for (auto &&i : A)
    {
        cin >> i;
    }

    LazySegTree<int, int> seg(A, 0, 0);
    int M;
    cin >> M;
    while (M--)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int i, j, k;
            cin >> i >> j >> k;
            seg.update(i, j, k);
        }
        else if (query == 2)
        {
            int i, j;
            cin >> i >> j;
            cout << seg.query(i, j) << "\n";
        }
        else
        {
            assert(false);
        }
    }

    return 0;
}