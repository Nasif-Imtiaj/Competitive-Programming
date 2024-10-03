struct Bit
{
    int bit[100050];  /// Size needs to be double of N.

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
