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
int total_palindromic_subsequence(string str)
{
    int len = str.length();
    int dp[len+5][len+5];
    memset(dp, 0,sizeof(dp));
    for (int i=0; i<len; i++)
        dp[i][i] = 1;
    for (int L=2; L<=len; L++)
    {
        for (int i=0; i<len; i++)
        {
            int k = L+i-1;
            if (str[i] == str[k])
                dp[i][k] = dp[i][k-1]+dp[i+1][k]+1;
            else
                dp[i][k] = dp[i][k-1]+dp[i+1][k]-dp[i+1][k-1];
        }
    }
    return dp[0][len-1];
}
int main()
{
//freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        string s;
        cin>>s;
        printf("Case %d: ",i);
        cout<<total_palindromic_subsequence(s)<<endl;
    }

    return 0;
}
