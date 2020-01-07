#include<bits/stdc++.h>
using namespace std;
int dp[100][20000];
int track[100][20000];
int cost[1000],weight[1000];
vector<int>ans;
int value,task,a;
void items(int b,int c,vector<int>temp)
{
    if(dp[b][c]==0)
    {
        if(temp.size()>ans.size())
        {
            ans.clear();
            for(int i=0; i<temp.size(); i++)
                ans.push_back(temp[i]);
        }
        return;
    }
    if(dp[b][c]!=dp[b-1][c])
    {
        temp.push_back(cost[b-1]);
        items(b-1,c-cost[b-1],temp);
    }
    else if(track[b][c]==1)
    {
        items(b-1,c,temp);
        temp.push_back(cost[b-1]);
        items(b-1,c-cost[b-1],temp);
    }
    else
        items(b-1,c,temp);
}
int O_1knapsack(int n,int val)
{
    int i,w;
    for(i=0; i<=n; i++)

        for(w=0; w<=val; w++)
        {
            if (i==0 || w==0)
                dp[i][w] = 0;
            else if(weight[i-1]<=w)
            {
                if(cost[i-1]+dp[i-1][w-weight[i-1]]>=dp[i-1][w])
                {
                    dp[i][w]=cost[i-1]+dp[i-1][w-weight[i-1]];
                    track[i][w]=1;
                }
                else
                {
                    dp[i][w]=dp[i-1][w];
                }
            }
            else
                dp[i][w]=dp[i-1][w];

        }
    return dp[n][val];
}
int main()
{
    //freopen("output.txt", "w", stdout);
    vector<int>temp;
    int i;
    while(cin>>value>>task)
    {
        for( i=0; i<task; i++)
        {
            cin>>cost[i];
            weight[i]=cost[i];
        }
        a=O_1knapsack(task,value);
        items(task,value,temp);
        for(i=ans.size()-1; i>=0; i--)
            cout<<ans[i]<<" ";
        cout<<"sum:"<<a<<endl;
        ans.clear();
        memset(track,0,sizeof(track));
        temp.clear();
    }
    return 0;
}

