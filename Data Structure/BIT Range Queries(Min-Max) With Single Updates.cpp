template<typename T>
struct BinaryIndexedTree
{
    int n;
    T neutral_value;
    vector<T>bit;
    function<T(T, T)> combine;

    BinaryIndexedTree(int n, vector<T>&arr, T neutral, function<T(T, T)> comb):  n(n), neutral_value(neutral), combine(comb)
    {
        bit.resize((2*n)+2,neutral_value);
        for(int i=1; i<=n; i++) bit[i+n]=arr[i];
        for(int i = n ; i >= 1 ; --i) bit[i] = combine(bit[i << 1], bit[(i << 1) | 1]);
    }

    void update(int idx, T val)
    {
        idx += n;
        bit[idx] = val;
        for(idx >>= 1 ; idx >= 1 ; idx >>= 1) bit[idx] = combine(bit[idx << 1], bit[(idx << 1) | 1]);
    }

    T query(int l, int r)
    {
        l += n, r += n;
        T res = neutral_value;
        for(; l<=r; l >>= 1,r >>= 1)
        {
            if(l & 1) res = combine(res, bit[l++]);
            if(!(r & 1)) res = combine(res, bit[r--]);
        }
        return res;
    }
};

/**
For Sum :
BinaryIndexedTree<int> bit(n,arr,0,[](int x,int y)
    {
        return x+y;
    });
*/
