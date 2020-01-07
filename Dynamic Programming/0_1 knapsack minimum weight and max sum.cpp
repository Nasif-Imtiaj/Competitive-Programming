#include<bits/stdc++.h>
using namespace std;
int dp[5000][5000];
int dp2[5000][5000];
int cost[5000],weight[5000];
int value,task,a;
void O_1knapsack(int n,int val)
{
    int i,w;
    for(i=0; i<=n; i++)

        for(w=0; w<=val; w++)
        {
            if (i==0 || w==0)
            {
                dp[i][w] = 0;
                dp2[i][w]=0;
            }
            else if(weight[i-1]<=w)
            {
                if(cost[i-1]+dp[i-1][w-weight[i-1]]>dp[i-1][w])
                {
                    dp[i][w]=cost[i-1]+dp[i-1][w-weight[i-1]];
                    dp2[i][w]=weight[i-1]+dp2[i-1][w-weight[i-1]];
                }
                else if(cost[i-1]+dp[i-1][w-weight[i-1]]==dp[i-1][w])
                {
                    dp[i][w]=cost[i-1]+dp[i-1][w-weight[i-1]];
                    dp2[i][w]=min(weight[i-1]+dp2[i-1][w-weight[i-1]],dp2[i-1][w]);
                }
                else
                {
                    dp[i][w]=dp[i-1][w];
                    dp2[i][w]=dp2[i-1][w];
                }
            }
            else
            {
                dp[i][w]=dp[i-1][w];
                dp2[i][w]=dp2[i-1][w];
            }

        }
    cout<<dp2[n][val]<<" "<<dp[n][val]<<endl;
}
int main()
{
    //freopen("output.txt", "w", stdout);
    int i;
    while(cin>>value>>task)
    {
        if(value==0 && task==0)
            break;
        for( i=0; i<task; i++)
        {
            cin>>weight[i];
            cin>>cost[i];
        }
        O_1knapsack(task,value);
    }
    return 0;
}
}
