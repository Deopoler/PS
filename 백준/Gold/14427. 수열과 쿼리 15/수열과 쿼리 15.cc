#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T>
class SegTree
{
private:
    int n;
    vector<T> tree;
    vector<T> array;

    int minIndex(int a, int b)
    {
        if (a == -1 || array[b] < array[a])
            return b;
        return a;
    }

    // node가 [nodeLeft..nodeRight] 표현
    // node를 루트로 하는 서브트리 초기화
    T init(const vector<T> &array, int node, int nodeLeft, int nodeRight)
    {
        if (nodeLeft == nodeRight)
            return tree[node] = nodeLeft;
        int mid = (nodeLeft + nodeRight) / 2;
        T leftValue = init(array, node * 2, nodeLeft, mid);
        T rightValue = init(array, node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = minIndex(leftValue, rightValue);
    }

    // node가 [nodeLeft..nodeRight] 표현
    // array[left..right]의 값 반환
    T query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        // 범위를 벗어나면 -1반환
        if (right < nodeLeft || nodeRight < left)
            return -1;

        if (left <= nodeLeft && nodeRight <= right)
            return tree[node];

        int mid = (nodeLeft + nodeRight) / 2;
        T leftValue = query(left, right, node * 2, nodeLeft, mid);
        T rightValue = query(left, right, node * 2 + 1, mid + 1, nodeRight);
        return minIndex(leftValue, rightValue);
    }

    // array[index] = newValue로 변경
    // node가 [nodeLeft..nodeRight] 표현
    // array[nodeLeft..nodeRight]의 값 반환
    T update(int index, T newValue, int node, int nodeLeft, int nodeRight)
    {
        // 범위를 벗어나면 원래 값 반환
        if (index < nodeLeft || nodeRight < index)
            return tree[node];

        // 리프노드이면 그대로
        if (nodeLeft == nodeRight)
            return tree[node];

        int mid = (nodeLeft + nodeRight) / 2;
        T leftValue = update(index, newValue, node * 2, nodeLeft, mid);
        T rightValue = update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
        return tree[node] = minIndex(leftValue, rightValue);
    }

public:
    SegTree(const vector<T> &array)
    {
        this->array = array;
        n = array.size();
        int height = (int)ceil(log2(n));
        tree.resize(1 << (height + 1));
        init(array, 1, 0, n - 1);
    }

    // array[left..right] 값 반환
    T query(int left, int right)
    {
        return query(left, right, 1, 0, n - 1);
    }

    // array[index] = newValue로 변경
    T update(int index, T newValue)
    {
        array[index] = newValue;
        return update(index, newValue, 1, 0, n - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    SegTree<int> seg(A);

    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int query;
        cin >> query;
        if (query == 1) // array[index] = value;
        {
            int index;
            int value;
            cin >> index >> value;
            seg.update(index - 1, value);
        }
        else if (query == 2) // mul(array)
        {
            cout << seg.query(0, N - 1) + 1 << "\n";
        }
    }

    return 0;
}