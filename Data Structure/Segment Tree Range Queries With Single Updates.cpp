struct SegmentTree
{
#define null INT_MIN
#define SIZE 100000
    int segment_tree[4 * SIZE];
    int neutral_value;

    inline int lc(int node)
    {
        return (node * 2) + 1;
    }
    inline int rc(int node)
    {
        return (node * 2) + 2;
    }

    function<int(int, int)> combine;

    SegmentTree(function<int(int, int)> comb, int neutral)
        : combine(comb), neutral_value(neutral) {}

    void build(int node, int s, int e)
    {
        if(s==e)
        {
            segment_tree[node] = arr[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(lc(node), s, mid);
        build(rc(node), mid + 1, e);
        segment_tree[node] = combine(segment_tree[lc(node)],segment_tree[rc(node)]);
    }
    void update(int node, int s, int e, int idx, int val)
    {
        if(idx<s || idx>e || s>e) return;
        if (s == idx && s==e)
        {
            segment_tree[node]=val;
            return;
        }
        int mid = (s + e) >> 1;
        update(lc(node), s, mid,idx,val);
        update(rc(node), mid + 1, e,idx,val);
        segment_tree[node] = combine(segment_tree[lc(node)],segment_tree[rc(node)]);
    }
    int query(int node, int s, int e, int l, int r)
    {
        if (l > e || s > r) return neutral_value;
        if (l <= s && e <= r) return segment_tree[node];
        int mid = (s + e) >> 1;
        return combine(query(lc(node), s, mid, l, r), query(rc(node), mid + 1, e, l, r));
    }
};

/**
SegmentTree sumTree([](int x, int y) { return x+y;},0);
SegmentTree minTree([](int x, int y) { return min(x,y);},INT_MAX);
SegmentTree maxTree([](int x, int y) { return max(x,y);},INT_MIN);
SegmentTree gcdTree([](int x, int y) { return __gcd(x, y);},0);
SegmentTree xorTree([](int x, int y) { return x ^ y; }, 0);
SegmentTree andTree([](int x, int y) { return x & y; }, -1);
SegmentTree orTree([](int x, int y) { return x | y; }, 0);
**/
