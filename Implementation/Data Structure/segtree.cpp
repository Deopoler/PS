#include <bits/stdc++.h>

using namespace std;

// RMQ(Range Minimum Query) 구현
template <typename T>
class SegTree
{
private:
    int n;
    vector<T> tree;

    // 처리 함수
    T op(T &a, T &b)
    {
        return min(a, b);
    }

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
        // 범위를 벗어나면 INF반환
        if (right < nodeLeft || nodeRight < left)
            return INT_MAX;

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

    SegTree(int n, T val = 0) : SegTree(vector<T> array(n, val)) {}

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