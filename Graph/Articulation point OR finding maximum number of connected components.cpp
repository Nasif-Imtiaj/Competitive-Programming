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
vector<int>graph[10050];
vector<int>entry_time,low_time;
int timer;
bool visited[10050];
set<int>s;
void dfs(int src,int parent)
{
    visited[src]=1;
    entry_time[src]=low_time[src]=timer++;
    int children=0;
    for(int i=0; i<graph[src].size(); i++)
    {
        int child=graph[src][i];
        if(child==parent)
            continue;
        if(visited[child]==1)
            low_time[src]=min(low_time[src],entry_time[child]);
        else
        {
            dfs(child,src);
            low_time[src]=min(low_time[src],low_time[child]);
            if(low_time[child]>=entry_time[src] && parent!=-1)
            {
                s.insert(src);//src is the point
            }
            children++;
        }
    }
    if(parent == -1 && children > 1)
        s.insert(src);
}
void find_bridges(int n)
{
    s.clear();
    fill(visited,visited+10020,0);
    entry_time.assign(n+2, -1);
    low_time.assign(n+2, -1);
    timer=0;
    for(int i=1; i<=n; i++)
        if(visited[i]==0)
            dfs(i,-1);
    co(s.size());
    for(int i=1; i<=n; i++)
        graph[i].clear();
}
int main()
{
//freopen("output.txt", "w", stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    int a,b;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    find_bridges(n);
    return 0;
}
