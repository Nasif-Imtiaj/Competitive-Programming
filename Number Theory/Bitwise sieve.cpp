int arr[5000054];
int status[(100000000/32)+2];
bool Check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int pos;
void bitwisesieve()
{
    int i,j,N=10000007;
   int sqrtN = int( sqrt( N ) );
    for( i = 3; i <= sqrtN; i += 2 )
    {
        if( Check(status[i>>5],i&31)==0)
        {
            for( j = i*i; j <= N; j += (i<<1) )
            {
                status[j>>5]=Set(status[j>>5],j & 31)   ;
            }
        }
    }
    arr[pos++]=2;
    for(i=3; i<=10000007; i+=2)
        if(Check(status[i>>5],i&31)==0)
            arr[pos++]=i;
}
