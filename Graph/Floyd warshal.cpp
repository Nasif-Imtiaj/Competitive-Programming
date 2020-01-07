#include<bits/stdc++.h>
using namespace std;
long long graph[1000][1000];
void warshal()
{
    int i,j,k;
    for(i=0; i<1000; i++)
        for(j=0; j<1000; j++)
            if(i==j)
                graph[i][j]=0;
            else
                graph[i][j]=INT_MAX;

    int nodes,edges,a,b,c;
    cin>>nodes>>edges;
    while(edges--)
    {
        cin>>a>>b>>c;
        graph[a][b]=c;
    }
    for(k=1; k<=nodes; k++)
        for(i=1; i<=nodes; i++)
            for(j=1; j<=nodes; j++)
            {
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }

    for(i=1; i<=nodes; i++)
    {
        for(j=1; j<=nodes; j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    warshal();
}
/*
5 8
1 4 3
1 3 5
2 1 3
5 2 4
4 2 1
5 4 2
3 4 2
4 3 1
*/
/*
3 3
1 2 3
2 3 2
3 1 -10
*/
/*
4 7
1 2 3
2 1 8
1 4 7
4 1 2
3 4 1
1 3 5
2 3 2
*/
