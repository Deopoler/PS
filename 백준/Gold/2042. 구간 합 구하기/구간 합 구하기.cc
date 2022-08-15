#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T>
class SegTree
{
private:
    int n;
    vector<T> range;

    // node가 [nodeLeft..nodeRight] 표현
    // node를 루트로 하는 서브트리 초기화
    T init(const vector<T> &array, int nodeLeft, int nodeRight, int node)
    {
        if (nodeLeft == nodeRight)
            return range[node] = array[nodeLeft];
        int mid = (nodeLeft + nodeRight) / 2;
        T leftValue = init(array, nodeLeft, mid, node * 2);
        T rightValue = init(array, mid + 1, nodeRight, node * 2 + 1);
        return range[node] = leftValue + rightValue;
    }

    // node가 [nodeLeft..nodeRight] 표현
    // array[left..right]의 값 반환
    T query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        // 범위를 벗어나면 0반환
        if (right < nodeLeft || nodeRight < left)
            return 0LL;

        if (left <= nodeLeft && nodeRight <= right)
            return range[node];

        int mid = (nodeLeft + nodeRight) / 2;
        T leftValue = query(left, right, node * 2, nodeLeft, mid);
        T rightValue = query(left, right, node * 2 + 1, mid + 1, nodeRight);
        return leftValue + rightValue;
    }

    // array[index] = newValue로 변경
    // node가 [nodeLeft..nodeRight] 표현
    // array[nodeLeft..nodeRight]의 값 반환
    T update(int index, T newValue, int node, int nodeLeft, int nodeRight)
    {
        // 범위를 벗어나면 원래 값 반환
        if (index < nodeLeft || nodeRight < index)
            return range[node];

        // 리프노드이면 값 변경
        if (nodeLeft == nodeRight)
            return range[node] = newValue;

        int mid = (nodeLeft + nodeRight) / 2;
        T leftValue = update(index, newValue, node * 2, nodeLeft, mid);
        T rightValue = update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
        return range[node] = leftValue + rightValue;
    }

public:
    SegTree(const vector<T> &array)
    {
        n = array.size();
        int height = (int)ceil(log2(n));
        range.resize(1 << (height + 1));
        init(array, 0, n - 1, 1);
    }

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K; // 수의 개수, update 수, query 수
    cin >> N >> M >> K;

    vector<ll> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    SegTree<ll> seg(a);

    for (int i = 0; i < M + K; i++)
    {
        int query;
        cin >> query;
        if (query == 1) // array[index] = value;
        {
            int index;
            ll value;
            cin >> index >> value;
            seg.update(index - 1, value);
        }
        else if (query == 2) // mul(array[left..right])
        {
            int left, right;
            cin >> left >> right;
            cout << seg.query(left - 1, right - 1) << "\n";
        }
    }

    return 0;
}