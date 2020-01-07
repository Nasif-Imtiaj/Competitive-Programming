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
int dp[10000][100];
int arr[20],value,coins;
int coin_change()
{
    int i,j,x,y;
    for(i=0; i<coins; i++)
        dp[0][i]=1;

    for(i=1; i<=value; i++)
    {
        for(j=0; j<coins; j++)
        {
            if(i-arr[j]>=0)
                x=dp[i-arr[j]][j];
            else
                x=0;
            if(j>0)
                y=dp[i][j-1];
            else
                y=0;
            dp[i][j]=x+y;
        }
    }
    return dp[value][coins-1];
}
int main()
{
//freopen("output.txt", "w", stdout);
    arr[0]=1;
    arr[1]=5;
    arr[2]=10;
    arr[3]=25;
    arr[4]=50;

    coins=5;
    while(cin>>value)
    {
        cout<<coin_change()<<endl;

    }
    return 0;
}

