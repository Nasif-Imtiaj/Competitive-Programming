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
vector<pair<int,int> >bridge;
void dfs(int src,int parent)
{
    visited[src]=1;
    entry_time[src]=low_time[src]=timer++;
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
            if(low_time[child]>entry_time[src])
                bridge.push_back(make_pair(src,child));
        }
    }
}
void find_bridges(int n)
{
    bridge.clear();
    fill(visited,visited+10020,0);
    fill(visited,visited+10020,0);
    entry_time.assign(n, -1);
    low_time.assign(n, -1);
    timer=0;
    for(int i=0; i<n; i++)
        if(visited[i]==0)
            dfs(i,-1);
    sort(bridge.begin(),bridge.end());
    int sz=bridge.size();
    printf("%d critical links\n",sz);
    for(int i=0; i<sz; i++)
        printf("%d - %d\n",bridge[i].first,bridge[i].second);
    for(i=0;i<n;i++)
        graph[i].clear();
}
int main()
{
//freopen("output.txt", "w", stdout);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int a;
        string s;
        scanf("%d",&a);
        getchar();
        cin>>s;
        int len=s.length();
        int connections=0;
        for(int j=1; j<len-1; j++)
            connections*=10,connections+=s[j]-48;
        int b;
        while(connections--)
        {
            scanf("%d",&b);
            graph[a].push_back(b);
        }
    }
    find_bridges(n);
    return 0;
}
