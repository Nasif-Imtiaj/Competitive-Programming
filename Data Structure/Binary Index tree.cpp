///For range/single update and single index query the following implementation can be used.
struct Bit
{
    int bit[100050];

    void build(int n)
    {
        memset(bit, 0, sizeof bit);
        for(int i=1; i<=n; i++) update(i,arr[i],n);
    }

    void update(int idx, int val, int n)
    {
        for (; idx <=n; idx += idx & -idx) bit[idx] += val;
    }

    void update(int l,int r,int val,int n)
    {
        update(l,val,n);
        update(r+1,-val,n);
    }

    int query(int idx)
    {
        int sum=0;
        for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
        return sum;
    }

} bit;


///For range Min/Max query with single index update the following implementation can be used.
struct Bit
{
    int bit[200100]; /// Size needs to be double of N.

    inline int combine(int x,int y)
    {
        return min(x,y); /// Change to max for max query.
    }

    void build(int n)
    {
        for(int i=1; i<=n; i++) bit[i+n]=arr[i];
        for(int i = n ; i >= 1 ; --i) bit[i] = combine(bit[i << 1], bit[(i << 1) | 1]);
    }

    void update(int idx, int val, int n)
    {
        idx += n;
        bit[idx] = val;
        for(idx >>= 1 ; idx >= 1 ; idx >>= 1) bit[idx] = combine(bit[idx << 1], bit[(idx << 1) | 1]);
    }

    int query(int l, int r,int n)
    {
        l += n, r += n;
        int res = INT_MAX; /// Change to INT_MIN for max query.
        for(; l<=r; l >>= 1,r >>= 1)
        {
            if(l & 1) res = combine(res, bit[l++]);
            if(!(r & 1)) res = combine(res, bit[r--]);
        }
        return res;
    }
} bit;
