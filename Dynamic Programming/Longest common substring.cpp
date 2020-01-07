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
int dp[1000][1000];
char track[1000][1000];
int len1,len2,i,j;
string s1,s2,s3,ans;
int res;
void PS(int a,int b)
{
    if(a==0 || b==0)
        return;

    if(track[a][b]=='D')
    {
        s3+=s1[a-1];
        PS(a-1,b-1);
    }
}

void Longest_common_substring(string s1,string s2)
{
    len1=s1.length();
    len2=len1;
    for(i=0; i<=max(len1,len2); i++)
    {
        dp[i][0]=0;
        dp[0][i]=0;
    }
    for(i=1; i<=len1; i++)
    {

        for(j=1; j<=len2; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                track[i][j]='D';
                res=max(res,dp[i][j]);
            }
        }
    }
    // return dp[len1][len2];
}
int main()
{

    cin>>s1;
    s2=s1;
    reverse(s2.begin(),s2.end());
    Longest_common_substring(s1,s2);
    cout<<res<<endl;



    return 0;
}

/*
AGGTAB
GXTXAYB
ans=4
*/
