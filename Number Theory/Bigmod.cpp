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
