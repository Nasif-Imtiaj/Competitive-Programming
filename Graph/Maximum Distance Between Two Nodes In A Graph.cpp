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
void bfs(int src,int dist[])
{
    queue <int> q;
    q.push(src);
    dist[src]=0;
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
        for(int i=0; i<graph[parent].size(); i++)
        {
            int child = graph[parent][i].first;
            int child_cost=graph[parent][i].second;
            if(dist[child]==-1)
            {
                dist[child]=dist[parent]+child_cost;
                q.push(child);
            }
        }
    }
}
int main()
{
//freopen("output.txt", "w", stdout);
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    int distance_for_first_search[nodes+5];
    int distance_for_second_search[nodes+5];
    for(int i=1; i<=nodes; i++)
    {
        distance_for_first_search[i]=-1;
        distance_for_second_search[i]=-1;
    }
    bfs(1,distance_for_first_search);
    int mx=0,mx_node;
    for(int i=1; i<=nodes; i++)
        if(distance_for_first_search[i]>mx)
        {
            mx=distance_for_first_search[i];
            mx_node=i;
        }
    bfs(mx_node,distance_for_second_search);
    int ans=0;
    for(int i=1; i<=nodes; i++)
    {
        ans=max(ans,max(distance_for_first_search[i],distance_for_second_search[i]));
    }
    cout<<ans<<endl;
    return 0;
}
