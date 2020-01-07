#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define p printf("bug\n");
#define co(q)  cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
int cost[1000][1000];
int track[1000][1000];
int row[]= {1,0,-1,0,1,-1,1,-1};
int colm[]= {0,1,0,-1,1,-1,-1,1};
int R,C;
void dijkstra(int input_x,int input_y)
{
    priority_queue<pair<int, pair<int,int> > >q;
    q.push(make_pair(cost[input_x][input_y],make_pair(input_x,input_y)));
    track[input_x][input_y]=0;
    while(!q.empty())
    {
        int father=q.top().second.first;
        int mother=q.top().second.second;
        q.pop();
        for(int i=0; i<8; i++)
        {
            int x=row[i]+father;
            int y=colm[i]+mother;
            if(0<=x && x<R && 0<=y && y<C)
            {
                if(track[x][y]==-1 || track[x][y]>cost[x][y]+track[father][mother])
                {
                    track[x][y]=cost[x][y]+track[father][mother];
                    q.push(make_pair(-1*track[x][y],make_pair(x,y)));
                }
            }
        }
    }
}
int main()
{
//freopen("output.txt", "w", stdout);

    int b,i,j;
    cin>>R>>C;
    for(i=0; i<R; i++)
    {
        for(j=0; j<C; j++)
        {
            cin>>cost[i][j];
            track[i][j]=-1;
        }
    }
    dijkstra(0,0);
    for(i=0; i<R; i++)
    {
        for(j=0; j<C; j++)
        {
            printf("%d ",track[i][j]);
        }
        cout<<endl;
    }
    cout<<track[R-1][C-1]<<endl;

    return 0;
}
