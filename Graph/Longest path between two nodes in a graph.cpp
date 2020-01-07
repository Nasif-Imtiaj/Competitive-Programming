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
vector<pair<int,int> >graph[100000];
int ans;

int dfs(int src,int parent)
{
    visit[src]=1;
    int path_cost=0;
    for(int i=0; i<graph[src].size(); i++)
    {
        int child=graph[src][i].first;
        int child_cost=graph[src][i].second;
        if(child!=parent)
        {
            visit[child]=1;
            int cur_cost=dfs(child,src)+child_cost;
            ans=max(ans,cur_cost+path_cost);
            path_cost=max(path_cost,cur_cost);
        }
    }
    return path_cost;
}
int main()
{
//freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    while(n--){
    int a,b,c;
    cin>>a>>b;
    c=1;
    graph[a].push_back(make_pair(b,c));
    graph[b].push_back(make_pair(a,c));
    }
    int temp=dfs(1,0);
    cout<<ans<<endl;
    return 0;
}
