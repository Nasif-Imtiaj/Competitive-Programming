#include<bit/stdc++.h>
using namespace std;
vector<int>graph[10020];
bool visit[10030];
int clr[100030];
int cycle;
void dfs(int src)
{
    visit[src]=1;
    clr[src]=1;
    for(int i=0; i<graph[src].size(); i++)
    {
        int child=graph[src][i];
        if(visit[child]==0)
            dfs(child);
        else if(clr[child]==1)
        {
            cycle=1;
            return;
        }
    }
    clr[src]=2;
}
int main()
{





}
