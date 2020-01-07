1.int divisorSum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += (n / i) * i;
    return sum;
}
///TC:O(1)
2.long long int sod(long long int a)
{
    long long int i=1,q,m,k,sum=0;
    q=sqrt(a);
    while(i<=q)
    {
        sum+=(i*(a/i));
        i+=1;
    }
    i=1;
    while(i<=(a/(q+1)))
    {
        m = a/i;
        k =a/(i+1);
        sum+=(i*(m*(m+1)- k* (k+1))/2);
        i += 1;
    }
    return sum;
}
///TC:O(sqrt(a))
