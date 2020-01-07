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
int arr[200],value,coins;
ll countt( int S[], int m, int n )
{
    ll table[n+1];
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
        {
            table[j]+=table[j-S[i]];
            table[j]%=100000007;
        }

    return table[n];
}
int main()
{
//freopen("output.txt", "w", stdout);
    int t,a,b,i;
    cin>>t;
    for(int j=1; j<=t; j++)
    {
        cin>>coins>>value;
        for(i=0; i<coins; i++)
        {
            cin>>arr[i];
        }
        printf("Case %d: ",j);
        cout<<countt(arr,coins,value)<<endl;
    }
    return 0;
}


