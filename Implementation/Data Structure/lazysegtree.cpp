#include <bits/stdc++.h>

using namespace std;

template <typename Value, typename Lazy>
struct Node
{
    Value value;
    Lazy lazy;
};

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
        return a + b;
    }

    // lazy로 현재 노드의 값 변경
    // 문제마다 수정(기본은 합 연산)
    void lazyUpdate(Lazy &lazy, int node, int nodeLeft, int nodeRight)
    {
        tree[node].value += lazy * (nodeRight - nodeLeft + 1);
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
                tree[node * 2].lazy += tree[node].lazy;
                tree[node * 2 + 1].lazy += tree[node].lazy;
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
                tree[node * 2].lazy += tree[node].lazy;
                tree[node * 2 + 1].lazy += tree[node].lazy;
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
                tree[node * 2].lazy += newValue;
                tree[node * 2 + 1].lazy += newValue;
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