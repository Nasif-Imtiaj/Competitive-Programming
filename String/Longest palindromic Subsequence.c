#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define p printf("bug\n");
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
int dp[1005][1005];
int longest_palindromic_subsequence(char s[])
{

    int len=strlen(s);
    for(int i=0; i<len; i++)
        dp[i][i]=1;

    for(int i=2; i<=len; i++)
    {
        for(int j=0; j<len-i+1; j++)
        {
            int k=i+j-1;
            if(s[j]==s[k] && i==2)
            {
                dp[j][k]=2;
            }
            else if(s[j]==s[k])
                dp[j][k]=dp[j+1][k-1] + 2;
            else
                dp[j][k]=max(dp[j][k-1], dp[j+1][k]);
        }
    }
    return dp[0][len-1];
}
int main()
{
//freopen("output.txt", "w", stdout);

    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        char s[1005];
        scanf("%s",s);
        printf("Case %d: %d\n",i,strlen(s)-longest_palindromic_subsequence(s));
    }



    return 0;
}

