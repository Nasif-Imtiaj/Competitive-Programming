struct Sparse_table
{
#define Level 20
#define Size 100050
    int sparse_table[Level][Size];
    int lg[Size];

    inline void calculateLog(int n)
    {
        for(int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;
    }

    inline void initTable(int n,int arr[])
    {
        for(int i=0; i<n; i++)
            sparse_table[0][i]=arr[i];
    }

    inline int combine(int a,int b)
    {
        return min(a,b); ///Supports min, max, sum, gcd, xor
    }

    void build(int n,int arr[])
    {
        initTable(n,arr);
        calculateLog(n);
        for(int i = 1; i <= lg[n]; i++)
            for(int j = 0; j < n - (1 << i) + 1; j++)
                sparse_table[i][j] = combine(sparse_table[i - 1][j],sparse_table[i - 1][j + (1 << (i - 1))]);
    }

    int query(int l,int r)
    {
        return combine(sparse_table[lg[r - l + 1]][l], sparse_table[lg[r - l + 1]][r - (1 << lg[r - l + 1]) + 1]);
    }
} st;
