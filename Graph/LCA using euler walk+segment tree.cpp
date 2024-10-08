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
int segment_tree[236145];
int depth[50000];
int first[50000];
vector<int>graph[50000];
vector<int>eulers_path;
bool visited[50000];
void dfs(int node,int height=0)
{
    visited[node] = 1;
    depth[node] = height;
    first[node] = eulers_path.size();
    eulers_path.push_back(node);
    for(int i=0; i<graph[node].size(); i++)
    {
        // cout<<i<<" "<<node<<endl;
        int child=graph[node][i];
        if(visited[child]==0)
        {
            dfs(child,height+1);
            eulers_path.push_back(node);
        }
    }
}
void construct_Segment_Tree(int low,int high,int node)
{
    if(low==high)
    {
        segment_tree[node]=eulers_path[low];
        return;
    }
    int mid=(low+high)/2;
    construct_Segment_Tree(low,mid,node*2+1);
    construct_Segment_Tree(mid+1,high,node*2+2);
    int l=segment_tree[node*2+1];
    int r=segment_tree[node*2+2];
    if(depth[l]<depth[r])
        segment_tree[node]=l;
    else
        segment_tree[node]=r;
}
int query(int st,int en,int low,int high,int node)
{
    if(st>high || en<low)
        return -1;
    if(st<=low && en>=high)
        return segment_tree[node];

    int mid=(low+high)/2;

    int left_side=query(st,en,low,mid,node*2+1);
    int right_side=query(st,en,mid+1,high,node*2+2);

    if(left_side==-1)
        return right_side;
    if(right_side==-1)
        return left_side;

    if(depth[left_side]<depth[right_side])
        return left_side;
    else
        return right_side;
}
int lca(int u,int v)
{
    int l=first[u];
    int r=first[v];
    cout<<l<<"   "<<r<<endl;
    if(l>r)
        swap(l,r);
    return query(l,r,0,eulers_path.size()-1,0);
}
int main()
{
//freopen("output.txt", "w", stdout);

    int n,m,a,b,c,q;
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    construct_Segment_Tree(0,eulers_path.size()-1,0);
    /* for(int i=0; i<eulers_path.size(); i++)
         cout<<eulers_path[i]<<" ";
     cout<<endl;
     for(int i=0; i<eulers_path.size(); i++)
         cout<<depth[eulers_path[i]]<<" ";
     cout<<endl;*/
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
    return 0;
}
