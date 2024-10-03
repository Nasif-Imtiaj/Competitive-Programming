struct MEX
{
    #define SIZE 100050
    unordered_map<int,int>ump;

    set<int>s;

    MEX()
    {
        for(int i=1; i<=SIZE; i++)
            s.insert(i);
    }

    inline void add(int x)
    {
        ump[x]++;
        if(ump[x]==1) s.erase(x);
    }

    inline void sub(int x)
    {
        ump[x]--;
        if(ump[x]==0) s.insert(x);
    }

    inline int getMex()
    {
        return *s.begin();
    }

} mex;

