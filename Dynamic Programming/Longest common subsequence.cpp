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
string s1,s2,s3;
void PS(int a,int b)
{
    if(a==0 || b==0)
        return;

    if(track[a][b]=='D')
    {
        s3+=s1[a-1];
        PS(a-1,b-1);
    }
    else if(track[a][b]=='L')
        PS(a,b-1);
    else
        PS(a-1,b);
}

int Longest_common_subsequence(string s1,string s2)
{
    int len1,len2,i,j;
    len1=s1.length();
    len2=s2.length();
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
            }
            else
            {
                if(dp[i-1][j]>=dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    track[i][j]='U';
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                    track[i][j]='L';
                }
            }
        }
    }
    return dp[len1][len2];
}
int main()
{

    cin>>s1>>s2;

    cout<<"Length of Longest common subsequence:"<<Longest_common_subsequence(s1,s2)<<endl;

    PS(s1.length(),s2.length());

    for(int i=0; i<=max(s1.length(),s2.length()); i++)
    {
        for(int j=0; j<=max(s1.length(),s2.length()); j++)
        {
          cout<<track[i][j]<<" ";
        }
        cout<<endl;
    }


    reverse(s3.begin(),s3.end());
    cout<<s3<<endl;


    return 0;
}

/*
AGGTAB
GXTXAYB
ans=4
*/
