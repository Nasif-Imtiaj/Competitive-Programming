#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dist[1000], visit[1000];
vector <int> graph[1000];
void bfs(int src)
{
    visit[src] = 1;
    queue <int> q;
    q.push(src);
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
        for(int i=0;i<graph[parent].size();i++)
        {
            int child = graph[parent][i];
            if(visit[child] == 0)
            {
                visit[child]=1;
                dist[child]=dist[parent]+1;
                q.push(child);
            }
        }
    }
}

int main()
{
    int n, e;
    printf("How many nodes and edges?\n");
    scanf("%d %d", &n, &e);
    for(int i=0;i<e;i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        vv[from].push_back(to);
        vv[to].push_back(from);
    }
    printf("Enter source and target\n");
    int src, tar;
    scanf("%d %d", &src, &tar);
    bfs(src);
    printf("%d\n", dist[tar]);
}
