int dp[25005];
int arr[200];
int knapsack(int n,int w)
{
    int i,j;
    for(i=0; i<=w; i++)
        dp[i]=0;
    for(i=1; i<=n; i++)
        for(j=w; j>0; j--)
            if(arr[i]<=j)
                dp[j]=max(dp[j],arr[i]+dp[j-arr[i]]);

    return dp[w];
}
