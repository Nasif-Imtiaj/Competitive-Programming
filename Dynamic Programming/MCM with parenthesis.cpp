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
#define inf 10000000
int dp[1000][1000],track[1000][1000],dim[1000];
void parenthesis(int a,int b)
{
    if(a==b)
    {
        cout<<"A"<<a;
        return;
    }
    cout<<"(";
    parenthesis(a,track[a][b]);
    parenthesis(track[a][b]+1,b);
    cout<<")";
}
int mcm(int st,int en)
{
    if(st==en)
        return 0;
    if(dp[st][en]!=-1)
        return dp[st][en];
    int ans=inf,i,lef,righ,sum,part;
    for(i=st; i<en; i++)
    {
        lef=mcm(st,i);
        righ=mcm(i+1,en);
        sum=lef+righ+dim[st-1]*dim[i]*dim[en];
        if(sum<ans)
        {
            ans=sum;
            part=i;
        }
    }
    dp[st][en]=ans;
    track[st][en]=part;
    return ans;
}
int main()
{
//freopen("output.txt", "w", stdout);
    int a,b,c,d,n,i,j=0;
    memset(dp,-1,sizeof(dp));
    cin>>a;
    for(i=0; i<a; i++)
    {
        cin>>dim[j]>>dim[j+1];
        j++;
    }
    cout<<mcm(1,a)<<endl;
    parenthesis(1,a);
    return 0;
}
/*
4
5 4
4 6
6 2
2 7
*/

