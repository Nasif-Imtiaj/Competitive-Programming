#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define bug cout<<"bug"<<endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
int arr[30][30],ans,n,temp[100],dp[20][1<<15+2];
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
bool check(int N,int pos)
{
    return (bool) (N & (1<<pos));
}
int bitmask(int pos,int mask)
{
    if(pos==n)
    {
        return 0;
    }
    if(dp[pos][mask]!=-1)
        return dp[pos][mask];
    int mx=0;
    for(int i=0; i<n; i++)
    {
        if(check(mask,i)==0)
        {
            int ans=arr[pos][i]+bitmask(pos+1,Set(mask,i));
             mx=max(mx,ans);
        }
    }
return dp[pos][mask]=mx;
}
int main()
{
//freopen("output.txt", "w", stdout);
    int t;
    scanf("%d",&t);
    for(int k=1; k<=t; k++)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&arr[i][j]);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",k,bitmask(0,0));
    }

    return 0;
}
