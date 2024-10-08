#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+5;
int arr[MAX];
template <typename T>
struct LazySegmentTree
{
private:
    std::vector<T> segment_tree, lazy_tree;
    T neutral_value;
    int invalid = INT_MIN;
    int n;
    int index = 1;

    inline int lc(int node)
    {
        return (node * 2) + 1;
    }

    inline int rc(int node)
    {
        return (node * 2) + 2;
    }

    inline void push(int node, int s, int e)
    {
        if (lazy_tree[node] == invalid) return;

        segment_tree[node] = lazy_tree[node];

        if (s != e)
        {
            lazy_tree[lc(node)] = lazy_tree[node];
            lazy_tree[rc(node)] = lazy_tree[node];
        }

        lazy_tree[node] = invalid;
    }

    inline T combine(T x, T y)
    {
        return x + y;
    }

    void build(int node, int s, int e)
    {
        lazy_tree[node] = invalid;

        if (s == e)
        {
            segment_tree[node] = arr[s];
            return;
        }

        int mid = (s + e) >> 1;
        build(lc(node), s, mid);
        build(rc(node), mid + 1, e);

        segment_tree[node] = combine(segment_tree[lc(node)], segment_tree[rc(node)]);
    }

    void update(int node, int s, int e, int l, int r, T val)
    {
        push(node, s, e);

        if (r < s || e < l) return;

        if (l <= s && e <= r)
        {
            lazy_tree[node] = val;
            push(node, s, e);
            return;
        }

        int mid = (s + e) >> 1;
        update(lc(node), s, mid, l, r, val);
        update(rc(node), mid + 1, e, l, r, val);

        segment_tree[node] = combine(segment_tree[lc(node)], segment_tree[rc(node)]);
    }

    T query(int node, int s, int e, int l, int r)
    {
        push(node, s, e);

        if (l > e || s > r) return neutral_value;

        if (l <= s && e <= r) return segment_tree[node];

        int mid = (s + e) >> 1;
        return combine(query(lc(node), s, mid, l, r), query(rc(node), mid + 1, e, l, r));
    }
public:

    LazySegmentTree(T neutral, int n): neutral_value(neutral), n(n)
    {
        segment_tree.resize(4 * n, neutral_value);
        lazy_tree.resize(4 * n, neutral_value);
    }

    void build(int n)
    {
        build(index,1,n);
    }

    void update(int l,int r, T val)
    {
        update(index,1,n,l,r,val);
    }

    T query(int l, int r)
    {
        return query(index,1,n,l,r);
    }
};


int main()
{
    int n = 100;
    LazySegmentTree<int> lSTree(0,n);
    for(int i=1; i<=n; i++)arr[i] = i;
    lSTree.build(n);
    for(int i=1; i<=n; i++)
        cout<<lSTree.query(i, n)<<endl;
    return 0;
}

