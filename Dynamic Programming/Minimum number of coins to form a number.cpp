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
int dp[10000][100];
int arr[2000],pos;
int mincoins(int value,int coins)
{
    if(value==0)
        return 0;
    int ans=INT_MAX;
    for(int i=0; i<coins; i++)
    {
        if(arr[i]<=value)
        {
           int sub_ans=mincoins(value-arr[i],coins);
            if (sub_ans != INT_MAX && sub_ans + 1 < ans)
            ans = sub_ans + 1;
        }
    }

return ans;
}

int main()
{
//freopen("output.txt", "w", stdout);

    int a,b,c,t,i,j;
    cin>>t;
    while(t--)
    {
        cin>>a;
        for(i=1; i<=sqrt(a); i++)
        {
            arr[i-1]=i*i;
        }
        b=mincoins(a,i-1);
        cout<<b<<endl;

    }
    return 0;
}
