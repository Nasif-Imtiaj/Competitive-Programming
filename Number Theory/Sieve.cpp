bool prime[MAX];
int prime_numbers[9999999],pos;
void sieve()
{
    prime[0]=1;
    prime[1]=1;
    for(int i=4; i<=MAX; i+=2)
        prime[i]=1;
    int root = sqrt(MAX);
    for(int i=3; i<=root; i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i; j<=MAX; j+=i)
            {
                prime[j]=1;
            }
        }
    }
    prime_numbers[pos++]=2;
    for(int i=3; i<MAX; i+=2)
        if(prime[i]==0)
            prime_numbers[pos++]=i;
}
