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
pair<int,pair<int,int> >mst[1000];
int parent[1000];
int root(int child)
{
    while(parent[child]!=child)
    {
        parent[child]=parent[parent[child]];
        child=parent[child];
    }
    return child;
}
void node_union(int x,int y)
{
    int a=root(x);
    int b=root(y);
    parent[min(a,b)]=parent[max(a,b)];
}
int kruskal(int nodes,int edges)
{
    for(int i=0; i<=nodes; i++)
        parent[i]=i;
    sort(mst,mst+edges);
    int x,y,cost,min_cost=0,i;
    for(i=0; i<edges; i++)
    {
        x=mst[i].second.first;
        y=mst[i].second.second;
        cost=mst[i].first;

        if(root(x)!=root(y))
        {
            min_cost+=cost;
            node_union(x,y);
        }
    }
    return min_cost;
}

int main()
{
//freopen("output.txt", "w", stdout);
    int i,a,b,c;
    cin>>nodes>>edges;
    for(i=0; i<edges; i++)
    {
        cin>>a>>b>>c;
        mst[i]=make_pair(c,make_pair(a,b));
    }
    cout<<kruskal()<<endl;
    return 0;
}
