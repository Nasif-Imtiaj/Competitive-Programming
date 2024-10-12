template <typename T>
struct LazySegmentTree
{
public:

    LazySegmentTree(int n, vector<T>&arr, T neutral, function<T(T, T)> combine)
        : n(n), neutral(neutral), combine(combine)
    {
        segmentTree.resize(4 * n, neutral);
        lazyTree.resize(4 * n, neutral);
        build(index,1,n, arr);
    }

    void update(int l,int r, T val)
    {
        update(index,1,n,l,r,val);
    }

    T query(int l, int r)
    {
        return query(index,1,n,l,r);
    }

private:
    int n = 0;
    int index = 1;
    T neutral;
    std::vector<T> segmentTree, lazyTree;
    function<T(T, T)> combine;

    inline int lc(int node)
    {
        return (node * 2) + 1;
    }

    inline int rc(int node)
    {
        return (node * 2) + 2;
    }

    void build(int node, int s, int e, vector<T>&arr)
    {
        lazyTree[node] = neutral;

        if (s == e)
        {
            segmentTree[node] = arr[s];
            return;
        }

        int mid = (s + e) >> 1;
        build(lc(node), s, mid, arr);
        build(rc(node), mid + 1, e, arr);

        segmentTree[node] = combine(segmentTree[lc(node)], segmentTree[rc(node)]);
    }

    inline void push(int node, int s, int e)
    {
        if (lazyTree[node] == neutral) return;

        segmentTree[node] = lazyTree[node];

        if (s != e)
        {
            lazyTree[lc(node)] = lazyTree[node];
            lazyTree[rc(node)] = lazyTree[node];
        }

        lazyTree[node] = neutral;
    }

    void update(int node, int s, int e, int l, int r, T val)
    {
        push(node, s, e);

        if (r < s || e < l) return;

        if (l <= s && e <= r)
        {
            lazyTree[node] = val;
            push(node, s, e);
            return;
        }

        int mid = (s + e) >> 1;
        update(lc(node), s, mid, l, r, val);
        update(rc(node), mid + 1, e, l, r, val);

        segmentTree[node] = combine(segmentTree[lc(node)], segmentTree[rc(node)]);
    }

    T query(int node, int s, int e, int l, int r)
    {
        push(node, s, e);

        if (l > e || s > r) return neutral;

        if (l <= s && e <= r) return segmentTree[node];

        int mid = (s + e) >> 1;
        return combine(query(lc(node), s, mid, l, r), query(rc(node), mid + 1, e, l, r));
    }
};


/**

Sample :
    LazySegmentTree<T> lazySegmentTree(n,arr,Neutral,[](T x,T y)
    {
        return Execution;
    });

                    T = int or long long

For SUM :       Neutral = 0,                  Execution = x+y
For MIN :       Neutral = INT_MAX,            Execution = min(x,y)
For MAX :       Neutral = INT_MIN,            Execution = max(x,y)
For GCD :       Neutral = 0,                  Execution = __gcd(x, y)
For XOR :       Neutral = 0,                  Execution = x ^ y
For AND :       Neutral = -1,                 Execution = x & y
For OR :        Neutral = 0,                  Execution = x | y

**/
