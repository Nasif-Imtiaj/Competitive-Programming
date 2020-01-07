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
string s1,s2,dp[200][200];
int len1,len2,i,j;
void Longest_common_subsequence()
{
    len1=s1.length();
    len2=s2.length();
    for(i=0; i<=max(len1,len2); i++)
    {
        dp[i][0]="";
        dp[0][i]="";
    }
    for(i=1; i<=len1; i++)
    {
        for(j=1; j<=len2; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+s1[i-1];
            }
            else
            {
                if(dp[i-1][j].size()>dp[i][j-1].size())
                {
                    dp[i][j]=dp[i-1][j];
                }
                else if(dp[i][j-1].size()>dp[i-1][j].size())
                {
                    dp[i][j]=dp[i][j-1];
                }
                else if(dp[i-1][j]<dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
    }
}
int main()
{

    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s1>>s2;
        printf("Case %d: ",cs++);
        Longest_common_subsequence();
        if(dp[len1][len2].size()==0)
            cout<<""<<endl;
        else
            cout<<dp[len1][len2]<<endl;
    }
    return 0;
}



