#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define p printf("bug\n");
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
int Sparse_Table[50000][20];
int father[50000];
int depth[50000];
bool visited[50000];
int nodes,edges;
vector<int>graph[10000];
void dfs(int src,int par,int height)
{
    visited[src]=1;
    father[src]=par;
    depth[src]=height;
    for(int i=0; i<graph[src].size(); i++)
    {
        int child=graph[src][i];
        if(child==par)
            continue;
        dfs(child,src,height+1);
    }
}
void initialize_LCA()
{
    memset(Sparse_Table,-1,sizeof(Sparse_Table));
    int i,j;
    for(i=0; i<nodes; i++)
        Sparse_Table[i][0]=father[i];

    for (j = 1; 1 << j < nodes; j++)
    {
        for (i = 0; i < nodes; i++)
        {
            if (Sparse_Table[i][j - 1] != -1)
            {
                Sparse_Table[i][j] = Sparse_Table[Sparse_Table[i][j - 1]][j - 1];
            }
        }
    }
}
int query(int l,int r)
{
    if(depth[l]<depth[r])
        swap(l,r);

    int k=log2(depth[l]);

    for(int i=k; i>=0; i--)
        if (depth[l] - (1 << i) >= depth[r])
            l=Sparse_Table[l][i];

    if(l==r)
        return l;

    for(int i=k; i>=0; i--)
        if (Sparse_Table[l][i]!=-1 && Sparse_Table[l][i]!=Sparse_Table[r][i])
        {
            l=Sparse_Table[l][i];
            r=Sparse_Table[r][i];
        }
    return father[l];
}
int main()
{
//freopen("output.txt", "w", stdout);

    int a,b;
    cin>>nodes>>edges;
    while(edges--)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,1,0);
    initialize_LCA();
    int q;
    cin>>q;
    while(q--){
        cin>>a>>b;
        cout<<query(a,b)<<endl;
    }





    return 0;
}

