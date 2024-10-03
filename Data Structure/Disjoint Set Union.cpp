struct DSU
{
#define Size 200050
    int parent[Size];
    int components[Size];

    void build(int n)
    {
        for(int i=1; i<=n; i++)
        {
            parent[i]=i;
            components[i]=1;
        }
    }

    inline int getComponentsCount(int node)
    {
        return components[getRoot(node)];
    }

    inline int getRoot(int node)
    {
        if(parent[node]==node)
            return parent[node];
        return parent[node] = getRoot(parent[node]);
    }

    inline bool isConnected(int u,int v)
    {
        return getRoot(u)==getRoot(v);
    }

    void combine(int u,int v)
    {
        u = getRoot(u);
        v = getRoot(v);
        if(u!=v)
        {
            if (components[u] < components[v])
                swap(u, v);
            parent[v] = u;
            components[u] += components[v];
        }
    }
} dsu;

/**
Sample submission : https://codeforces.com/contest/2020/submission/284219454
**/
