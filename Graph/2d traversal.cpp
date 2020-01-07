int visit[1200][1200],dis[1200][1200];
int R,C;
int row[]= {1,0,-1,0,1,-1,1,-1};
int colm[]= {0,1,0,-1,1,-1,-1,1};
void bfs(int input_x,int input_y)
{
    queue<pair<int,int> >q;
    visit[input_x][input_y] = 1;
    dis[input_x][input_y]   = 0;
    q.push(make_pair(input_x,input_y));
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<8; i++)
        {
            int u = x+row[i];
            int v = y+colm[i];
            if(0<=u && u<R && 0<=v && v<C)
            {
                if(visit[u][v]==0)
                {
                    visit[u][v]=1;
                    dis[u][v] = dis[x][y]+1;
                    q.push(make_pair(u,v));
                }
            }
        }
    }
    return ;
}
