#include<bits/stdc++.h>
using namespace std;
int store[10000];
int minCoinChange(int coins,int value)
{
    int dp[coins+2][value+2];
    for(int i=0; i<=value; i++)
    {
        dp[0][i]=INT_MAX;///making all the coloumn index from 0 to value max

    }
    for(int i=0; i<=coins; i++) ///making all the row index of coins of the top 0
        dp[i][0]=0;
    for(int i=1; i<=coins; i++)
    {
        for(int j=1; j<=value; j++)
        {
            if(j<store[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]= min(dp[i-1][j],dp[i][j-store[i]]+1);
        }
    }
    return dp[coins][value];
}
int main()
{
       int n,i,t,make;
        cin>>n;
        cin>>make;
        for(i=1;i<=n;i++)
            cin>>store[i];
        cout<<minCoinChange(n,make)<<endl;

}
