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

template <typename T>
class SegTree
{
private:
    int n;
    T identity;
    vector<T> tree;

    // 좌측 노드와 우측 노드의 연산 정의
    // 결합법칙을 만족하고 항등원이 존재해야 함
    // 문제마다 수정(기본은 합 연산)
    T merge(const T &a, const T &b)
    {
        return a + b;
    }

    // 값 업데이트 시 현재의 값과 새로운 값과의 관계 정의
    T update_value(const T &current, const T &new_value)
    {
        return new_value;
    }

    // node가 [nodeLeft..nodeRight] 표현
    // node를 루트로 하는 서브트리 초기화
    void init(const vector<T> &array)
    {
        // 초기값 대입
        for (int i = 0; i < n; i++)
            tree[n + i] = array[i];

        // 나머지 초기화
        for (int i = n - 1; i >= 1; i--)
            tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
    }

public:
    SegTree(const vector<T> &array, T identity) : identity(identity)
    {
        n = array.size();
        int height = (int)ceil(log2(n));
        tree.resize(1 << (height + 1));
        init(array);
    }

    SegTree(int n, T identity) : SegTree(vector<T>(n, identity), identity) {}

    // array[left..right]의 값 반환
    T query(int left, int right)
    {
        left += n;
        right += n;
        T ret = identity;
        while (left <= right)
        {
            if (left % 2 == 1)
                ret = merge(ret, tree[left++]);
            if (right % 2 == 0)
                ret = merge(ret, tree[right--]);
            left /= 2;
            right /= 2;
        }
        return ret;
    }

    // array[index] = newValue로 변경
    // array[nodeLeft..nodeRight]의 값 반환
    void update(int index, T newValue)
    {
        index += n;
        tree[index] += newValue;
        for (index /= 2; index >= 1; index /= 2)
            tree[index] = update_value(tree[index], merge(tree[index * 2], tree[index * 2 + 1]));
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    vll A(n);
    vll diff(n);
    cin >> A[0];
    diff[0] = A[0];
    for (int i = 1; i < n; i++)
    {
        cin >> A[i];
        diff[i] = A[i] - A[i - 1];
    }
    SegTree<ll> seg(diff, 0);
    cin >> m;
    while (m--)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int i, j, k;
            cin >> i >> j >> k;
            seg.update(i - 1, k);
            if (j < n)
                seg.update(j, -k);
        }
        else if (query == 2)
        {
            int x;
            cin >> x;
            cout << seg.query(0, x - 1) << "\n";
        }
        else
        {
            assert(false);
        }
    }

    return 0;
}