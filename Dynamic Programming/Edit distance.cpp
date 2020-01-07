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
string s1,s2;
int Edit_distance(string s1,string s2)
{
    int len1,len2,i,j;
    len1=s1.length();
    len2=s2.length();
    for(i=1; i<=max(len1,len2); i++)
    {
        dp[i][0]=i;
        dp[0][i]=i;
    }
    for(i=1; i<=len1; i++)
    {

        for(j=1; j<=len2; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }
    return dp[len1][len2];
}
int main()
{

    cin>>s1>>s2;

    cout<<"Lowest Edit distance:"<<Edit_distance(s1,s2)<<endl;


    return 0;
}

/*
AKASH
AKSHAY
ans=3
*/
