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
ll NOD(ll a)
{
    ll sum=0;
    ll b=sqrt(a);
    for(int i=1; i<=b; i++)
    {
        sum+=(a/i);
    }
    sum=sum*2-(b*b);
    return sum;
}
int main()
{
//freopen("output.txt", "w", stdout);


    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<NOD(r-1)-NOD(l-1)<<endl;
    }



    return 0;
}
