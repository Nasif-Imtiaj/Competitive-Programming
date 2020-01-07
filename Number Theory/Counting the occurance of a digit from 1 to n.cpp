long long countDigitOccurance(long long n, long long d)
{
    long long res=0;
    for(long long i=1; i<=n; i*=10)
    {
        long long x=n/i;
        long long y=n%i;
        if(d>0)
        {
            if(x%10==d)
                res+=x/10*i+y+1;
            else if(x%10<d)
                res+=x/10*i;
            else
                res+=(x/10+1)*i;
        }
        else
        {
            if(x%10==d)
                res+=(x>9?x/10-1:0)*i+y+1;
            if(x%10>d)
                res+=x/10*i;
        }
    }
    return res;
}
/// log N
