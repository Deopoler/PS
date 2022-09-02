#include <bits/stdc++.h>

using namespace std;

// 반복문 구현
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
    T merge(T &a, T &b)
    {
        return a + b;
    }

    // 값 업데이트 시 현재의 값과 새로운 값과의 관계 정의
    T update_value(T &current, T &new_value)
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
        tree[index] = newValue;
        for (index /= 2; index >= 1; index /= 2)
            tree[index] = update_value(tree[index], merge(tree[index * 2], tree[index * 2 + 1]));
    }
};

// 재귀 구현
// template <typename T>
// class SegTree
// {
// private:
//     int n;
//     T identity;
//     vector<T> tree;

//     // 좌측 노드와 우측 노드의 연산 정의
//     // 결합법칙을 만족하고 항등원이 존재해야 함
//     // 문제마다 수정
//     T merge(T &a, T &b)
//     {
//         return T();
//     }

//     // node가 [nodeLeft..nodeRight] 표현
//     // node를 루트로 하는 서브트리 초기화
//     T init(const vector<T> &array, int node, int nodeLeft, int nodeRight)
//     {
//         if (nodeLeft == nodeRight)
//             return tree[node] = array[nodeLeft];
//         int mid = (nodeLeft + nodeRight) / 2;
//         T leftValue = init(array, node * 2, nodeLeft, mid);
//         T rightValue = init(array, node * 2 + 1, mid + 1, nodeRight);
//         return tree[node] = merge(leftValue, rightValue);
//     }

//     // node가 [nodeLeft..nodeRight] 표현
//     // array[left..right]의 값 반환
//     T query(int left, int right, int node, int nodeLeft, int nodeRight)
//     {
//         // 범위를 벗어나면 항등원반환
//         if (right < nodeLeft || nodeRight < left)
//             return identity;

//         if (left <= nodeLeft && nodeRight <= right)
//             return tree[node];

//         int mid = (nodeLeft + nodeRight) / 2;
//         T leftValue = query(left, right, node * 2, nodeLeft, mid);
//         T rightValue = query(left, right, node * 2 + 1, mid + 1, nodeRight);
//         return merge(leftValue, rightValue);
//     }

//     // array[index] = newValue로 변경
//     // node가 [nodeLeft..nodeRight] 표현
//     // array[nodeLeft..nodeRight]의 값 반환
//     T update(int index, T newValue, int node, int nodeLeft, int nodeRight)
//     {
//         // 범위를 벗어나면 원래 값 반환
//         if (index < nodeLeft || nodeRight < index)
//             return tree[node];

//         // 리프노드이면 값 변경
//         if (nodeLeft == nodeRight)
//             return tree[node] = newValue;

//         int mid = (nodeLeft + nodeRight) / 2;
//         T leftValue = update(index, newValue, node * 2, nodeLeft, mid);
//         T rightValue = update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
//         return tree[node] = merge(leftValue, rightValue);
//     }

// public:
//     SegTree(const vector<T> &array, T identity) : identity(identity)
//     {
//         n = array.size();
//         int height = (int)ceil(log2(n));
//         tree.resize(1 << (height + 1));
//         init(array, 1, 0, n - 1);
//     }

//     SegTree(int n, T identity) : SegTree(vector<T>(n, identity), identity) {}

//     // array[left..right] 값 반환
//     T query(int left, int right)
//     {
//         return query(left, right, 1, 0, n - 1);
//     }

//     // array[index] = newValue로 변경
//     T update(int index, T newValue)
//     {
//         return update(index, newValue, 1, 0, n - 1);
//     }
// };