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
int visit[10000],dist[10000];
vector<int>graph[10000];
vector<int> comp;
bool used[10000];
void dfs(int src)
{
    visit[src] = 1;
    comp.push_back(src) ;
    for(int i=0; i<graph[src].size(); i++)
    {
        int node = graph[src][i];
        if(visit[node] == 0)
        {
            dist[node] = dist[src]+1;
            dfs(node);
        }
    }
}
void find_comps(int n)
{
    for(int i = 1; i <=n ; i++)
        used [i] = 0;
    for(int i = 1; i <=n ; i++)
        if (!used[i])
        {
            comp.clear();
            dfs(i);
            cout << "Component:" ;
            for (size_t j = 0; j < comp.size(); ++j)
                cout << ' ' << comp[j];
            cout << endl ;
        }
}
int main()
{
//freopen("output.txt", "w", stdout);








    return 0;
}
