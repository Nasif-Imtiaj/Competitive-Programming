#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define bug cout<<"bug"<<endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
pair<int,pair<int,int> >mst[50000];
int parent[20000];
vector<pair<int,pair<int,int> > >v;
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
int kruskal(int n,int edges)
{

    for(int i=0; i<=n; i++)
        parent[i]=i;
    int x,y,cost,min_cost=0,i,selected=0;
    for(i=0; i<edges; i++)
    {
        x=mst[i].second.first;
        y=mst[i].second.second;
        cost=mst[i].first;

        if(root(x)!=root(y))
        {
            v.push_back(make_pair(cost,make_pair(x,y)));
            selected++;
            min_cost+=cost;
            node_union(x,y);
        }
    }
    if(selected==n-1) /// to check if connected or not
        return min_cost;
    else
        return INT_MAX;
}
int second_kruskal(int n,int edges,int u,int v,int w)
{
    for(int i=0; i<=n; i++)
        parent[i]=i;
    int x,y,cost,min_cost=0,i,selected=0,skip_count=0;
    for(i=0; i<edges; i++)
    {
        x=mst[i].second.first;
        y=mst[i].second.second;
        cost=mst[i].first;
        if((x==u && y==v && cost==w && skip_count<2) || (x==v && y==u && cost==w && skip_count<2))
        {
            skip_count++;///need to skip only 2 if there are multiple of the same type of node
            continue;
        }
        if(root(x)!=root(y))
        {
            selected++;
            min_cost+=cost;
            node_union(x,y);
        }
    }
    if(selected==n-1) /// to check if connected or not
        return min_cost;
    else
        return INT_MAX;
}
int main()
{
//freopen("output.txt", "w", stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,e;
        scanf("%d %d",&n,&e);
        e*=2;
        for(int i=0; i<e; i+=2)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            mst[i]=make_pair(c,make_pair(a,b));
            mst[i+1]=make_pair(c,make_pair(b,a));
        }
        sort(mst,mst+e);
        int k=kruskal(n,e);
        printf("Case #%d : ",cs++);
        if(k!=INT_MAX)///also checks if the graph is connected or not
        {
            int ans=INT_MAX;
            for(int i=0; i<n-1; i++)
            {
                int l=second_kruskal(n,e,v[i].second.first,v[i].second.second,v[i].first);
                ans=min(ans,l);
            }
            if(ans==INT_MAX)
                printf("No second way\n");
            else
                printf("%d\n",ans);
        }
        else
            printf("No way\n");
        v.clear();
    }
    return 0;
}
