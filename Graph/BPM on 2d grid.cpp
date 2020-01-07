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
vector<int>graph[1005];
bool visit[1005];
int connection[1005],grid[200][200],color[1005],check[200][200];
string s[1005];
int row[]= {1,0,-1,0,1,-1,1,-1};
int colm[]= {0,1,0,-1,1,-1,-1,1};
bool BPM(int node)
{
    int sz=graph[node].size();
    for(int i=0; i<sz; i++)
    {
        int child=graph[node][i];
        if(visit[child]==0)
        {
            visit[child]=1;
            if(connection[child]<0 || BPM(connection[child]))
            {
                connection[child]=node;
                return true;
            }
        }
    }
    return false;
}
int maxBPM(int n)
{
    memset(connection,-1,sizeof(connection));
    int res=0;
    for(int i=0; i<n; i++)
    {

        memset(visit,0,sizeof(visit));
        if(BPM(i))
            res++;

    }
    return res;
}
void bfs(int x,int y,int n,int m)
{
    queue<pair<int,int> >q;
    q.push(make_pair(x,y));
    int num=grid[x][y];
    color[num]=1;
    check[x][y]=1;
    while(!q.empty())
    {
        int i=q.front().first;
        int j=q.front().second;
        int parent=grid[i][j];
        q.pop();
        for(int k=0; k<4; k++)
        {
            int u=i+row[k];
            int v=j+colm[k];
            if(u>=0 && u<n && v>=0 && v<m)
            {
                int child=grid[u][v];
                if(s[u][v]=='*' && check[u][v]==0)
                {
                    check[u][v]=1;
                    if(color[parent]==1 && color[child]!=1)
                    {
                        color[child]=2;
                        graph[parent].push_back(child);
                        q.push(make_pair(u,v));
                    }
                    else
                    {
                        color[child]=1;
                        graph[child].push_back(parent);
                        q.push(make_pair(u,v));
                    }
                }
                else if(s[u][v]=='*')
                {
                    if(color[parent]==1)
                        graph[parent].push_back(child);
                    else
                        graph[child].push_back(parent);
                }
            }
        }
    }
}
void init(int n,int m)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            check[i][j]=0;
    for(int i=0; i<n*m+5; i++)
    {
        graph[i].clear();
        color[i]=0;
    }
}
int main()
{
//freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        int n,m,cnt=0,number=1;
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                grid[i][j]=number++;
                if(s[i][j]=='*')
                    cnt++;
            }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(s[i][j]=='*' && check[i][j]==0)
                {
                    bfs(i,j,n,m);
                }
            }
        }
        int ans=maxBPM(n*m+5);
        cnt-=ans*2;
        printf("Case %d: %d\n",k,ans+cnt);
        init(n,m);
    }
    return 0;
}
