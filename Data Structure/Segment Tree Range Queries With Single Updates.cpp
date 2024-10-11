template<typename T>
struct SegmentTree
{
public:

    SegmentTree(int n, vector<T>&arr, T neutral, function<T(T, T)> combine)
        : n(n), neutral(neutral), combine(combine)
    {
        segmentTree.resize(4 * n, neutral);
        build(index,1,n,arr);
    }
    void update(int idx, T val)
    {
        update(index,1,n,idx,val);
    }

    T query(int l, int r)
    {
        return query(index,1,n,l,r);
    }

private:
    int n = 0;
    int index = 1;
    T neutral;
    std::vector<T> segmentTree;
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
        if(s == e)
        {
            segmentTree[node] = arr[s];
            return;
        }

        int mid = (s + e) >> 1;
        build(lc(node), s, mid, arr);
        build(rc(node), mid + 1, e, arr);

        segmentTree[node] = combine(segmentTree[lc(node)], segmentTree[rc(node)]);
    }

    void update(int node, int s, int e, int idx, T val)
    {
        if(idx < s || idx > e || s > e) return;

        if(s == e)
        {
            segmentTree[node] = val;
            return;
        }

        int mid = (s + e) >> 1;
        update(lc(node), s, mid, idx, val);
        update(rc(node), mid + 1, e, idx, val);

        segmentTree[node] = combine(segmentTree[lc(node)], segmentTree[rc(node)]);
    }

    T query(int node, int s, int e, int l, int r)
    {
        if(l > e || r < s) return neutral;

        if(l <= s && e <= r) return segmentTree[node];

        int mid = (s + e) >> 1;
        return combine(query(lc(node), s, mid, l, r), query(rc(node), mid + 1, e, l, r));
    }
};

/**

Sample :
    SegmentTree<T> segmentTree(n,arr,Neutral,[](T x,T y)
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
