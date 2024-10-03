struct Query
{
    inline void add(int pos)
    {
    }

    inline void sub(int pos)
    {
    }

    inline int getAnswer()
    {
    }

    inline void reset()
    {
    }
};

struct Update
{
    int idx, pre, nxt;
};

struct Mos
{
    struct Data
    {
        int l, r, id, t, blcl, blcr;
        Data(int _l, int _r, int _id, int _t,int block)
        {
            l = _l, r = _r, id = _id, t = _t, blcl = l / block, blcr = r / block;
        }
        bool operator < (const Data &p) const
        {
            if(blcl != p.blcl) return l < p.l;
            if(blcr != p.blcr) return r < p.r;
            return t < p.t;
        }
    };

    int res,L,R,T,blockSize;
    vector<Data>queries;
    vector<Update>updates;
    vector<int>ans;
    Query query;

    inline void build(int n)
    {
        res=0,L=1,R=0,T=0;
        blockSize = pow(n, 0.667);
        queries.clear();
        updates.push_back({-1,-1,-1});
        ans = vector<int>(n, 0);
    }

    inline void addQuery(int l,int r,int id)
    {
        queries.push_back(Data(l,r,id,updates.size()-1,blockSize));
    }

    inline void addUpdate(int idx,int pre,int nxt)
    {
        updates.push_back(Update({idx,pre,nxt}));
    }

    inline void sortQueries()
    {
        sort(queries.begin(),queries.end());
    }

    inline int update(int idx,int val)
    {
        if(idx>=L && idx<=R)
        {
            query.sub(idx);
            arr[idx]=val;
            query.add(idx);
        }
        else
            arr[idx]=val;
    }

    inline int solve(int l,int r,int t)
    {
        while(T < t) ++T, update(updates[T].idx, updates[T].nxt);
        while(T > t) update(updates[T].idx, updates[T].pre), --T;
        while(R < r) query.add(++R);
        while(L > l) query.add(--L);
        while(R > r) query.sub(R--);
        while(L < l) query.sub(L++);

        return query.getAnswer();
    }

    inline void reset()
    {
        query.reset();
    }
} mos;

