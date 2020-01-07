#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define p printf("bug\n");
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = 1000003;
const int MAX = 1e6;
#define pi acos(-1)
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
ll fact[1000005],inverse[1000005];
ll Bigmod(int a,int b)
{
    if(b==0)
        return 1%MOD;
    ll x=Bigmod(a,b/2);
    x=(x*x)%MOD;
    if(b%2==1)
        x=(x*a)%MOD;
    return x;
}
ll nCr(int x, int y)
{
    if(x<0 || y<0 || x<y)
        return 0;
    return fact[x] * (inverse[y] * inverse[x - y] % MOD) % MOD;
}
int main()
{
//freopen("output.txt", "w", stdout);

    fact[0]=1;
    for(int i=1; i<=1000000; i++)
        fact[i]=fact[i-1]*1LL*i%MOD;
    inverse[1000000]=Bigmod(fact[1000000],MOD-2);
    for(int i=1000000; i>0; i--)
    {
        inverse[i-1]=i* 1LL*inverse[i] % MOD;
    }
    printf("%lld",nCr(45,2));

    return 0;
}
