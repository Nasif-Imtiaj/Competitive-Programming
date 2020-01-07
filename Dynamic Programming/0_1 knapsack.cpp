#include<bits/stdc++.h>
using namespace std;
int dp[100][20000];
int cost[1000],weight[1000];
int value,task,a;
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
    int i;
    while(cin>>value>>task)
    {
        for( i=0; i<task; i++)
        {
            cin>>cost[i];
            weight[i]=cost[i];
        }
        a=O_1knapsack(task,value);
        cout<<a<<endl;
    }
    return 0;
}
