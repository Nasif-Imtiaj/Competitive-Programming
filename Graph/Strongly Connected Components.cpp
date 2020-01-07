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
vector<int>graph_direct[20050];
vector<int>graph_reversed[20050];
stack<int>order;
stack<int>component;
bool visit_direct[20050];
bool visit_reversed[20050];
int outdegree[20050],indegree[20050];
int parent[20050];
void dfs_direct(int src)
{
    visit_direct[src]=1;
    for(int i=0; i<graph_direct[src].size(); i++)
    {
        int child=graph_direct[src][i];
        if(visit_direct[child]==0)
            dfs_direct(child);
    }
    order.push(src);
}
void dfs_reversed(int src,int par)
{
    visit_reversed[src]=1;
    parent[src]=par;///keeping track for component degrees
    for(int i=0; i<graph_reversed[src].size(); i++)
    {
        int child=graph_reversed[src][i];
        if(visit_reversed[child]==0)
            dfs_reversed(child,par);
        else if(parent[child]!=parent[src])
        {
            indegree[parent[child]]++;///finding the component degrees
            outdegree[parent[src]]++;///finding the component degrees
        }
    }
    component.push(src);
}
void init(int n)
{
    while(!order.empty())
    {
        order.pop();
    }
    while(!component.empty())
    {
        component.pop();
    }
    for(i=1; i<=n; i++)
    {
        graph_direct[i].clear();
        graph_reversed[i].clear();
        visit_direct[i]=0;
        visit_reversed[i]=0;
        indegree[i]=0;
        outdegree[i]=0;
    }
}
int main()
{
//freopen("output.txt", "w", stdout);
    int n,m,i;
    scanf("%d %d",&n,&m);

    while(m--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        graph_direct[a].push_back(b);
        graph_reversed[b].push_back(a);
    }
    for(i=1; i<=n; i++)
        if(visit_direct[i]==0)
            dfs_direct(i);
    // cout<<endl<<endl;
    int numbering_component_degres=1;
    while(!order.empty())
    {
        int st=order.top();
        order.pop();
        if(visit_reversed[st]==0)
            dfs_reversed(st,numbering_component_degres++);
        else
            continue;
        while(!component.empty())
        {
            int ft=component.top();
            cout<<ft<<" ";///printing the components
            component.pop();
        }
        cout<<endl;
    }
    init(n);


    return 0;
}
