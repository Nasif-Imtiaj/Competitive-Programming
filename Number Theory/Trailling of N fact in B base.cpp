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
ll find_the_highest_power_b_that_divides_nFact(ll N,ll B)
{

    ll mul=1;
    ll cnt=0;
    ll temp;
    while(mul<=N/B)
    {
        mul*=B;
        cnt+=(N/mul);
    }
    return cnt;
}
ll find_trailling_zero_in_B_base(ll N,ll B)
{

    ll ans=(ll)1000000000000000000 ;
    vector<pair<ll,ll> >prime_factors;
    if(B%2==0)
    {
        ll cnt=0;
        while(B%2==0)
        {
            B/=2;
            cnt++;
        }
        prime_factors.push_back(make_pair(2,cnt));
    }
    for(ll i=3; i<=sqrt(B); i+=2)
    {
        if(B%i==0)
        {
            int cnt=0;
            while(B%i==0)
            {
                B/=i;
                cnt++;
            }
            prime_factors.push_back(make_pair(i,cnt));
        }
    }
    if(B!=1)
    {
        prime_factors.push_back(make_pair(B,1));
    }
    // N=temp;
    int pos=prime_factors.size();
    for(int i=0; i<pos; i++)
    {
        ans=min(ans,find_the_highest_power_b_that_divides_nFact(N,prime_factors[i].first)/prime_factors[i].second);
    }
    return ans;
}
int main()
{
//freopen("output.txt", "w", stdout);


    ll n,b;
    cin>>n>>b;
    cout<<find_trailling_zero_in_B_base(n,b)<<endl;




    return 0;
}




