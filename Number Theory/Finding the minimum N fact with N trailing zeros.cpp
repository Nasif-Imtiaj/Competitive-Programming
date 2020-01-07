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
ll find_trailling_zero(ll a)
{
    ll z=0,c=5;
    while(a>=c)
    {
        z+=a/c;
        c*=5;
    }
    return z;
}
ll BS(ll a)
{
    ll ans=0,b;
    ll l=1,r=a*5;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        b=find_trailling_zero(mid);
        if(b==a)
        {
            if(ans==0)
                ans=mid;
            else
                ans=min(ans,mid);
            r=mid-1;
        }
        else if(b<a)
        {
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return ans;
}
int main()
{
    // freopen("output.txt", "w", stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        ll a,b,c;
        cin>>a;
        b=BS(a);
        printf("Case %d: ",cs++);
        if(b)
            printf("%lld\n",b);
        else
            printf("impossible\n");
    }
    return 0;
}

