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
int main()
{
//freopen("output.txt", "w", stdout);

  int t,cs=1;
  scanf("%d",&t);
  while(t--){
    ll a,b,c,d;
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    ll ans=__gcd(llabs(a-c),llabs(b-d))+1;
    printf("Case %d: %lld\n",cs++,ans);

  }






    return 0;
}
