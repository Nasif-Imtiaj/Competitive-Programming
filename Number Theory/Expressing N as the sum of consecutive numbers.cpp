
/*(use sum of arithmetic progression:n = r/2* (2 * a + r - 1) or
a = (2 * n + r - r2)/(2 * r); as n is given,
brute force all values of r from
root 2n down to 1, stop at the first valid a)
*/
int check_valid(int n,int r)  // n = r/2 ( 2a + r - 1 )
{
    int a=2*n+r-(r*r);
    if(a%(2*r)==0)
        return a/(2*r);
    return -1;
}
int main()
{
//freopen("output.txt", "w", stdout);
    int n;
    while(cin>>n)
    {
        if(n==-1)
            break;
        int m=sqrt(2*n);
        for(int i=m; i>0; i--)
        {
            int c=check_valid(n,i);
            if(c!=-1)
            {
                cout<<n<< " = "<<c<< " + ... + "<<c+i-1<<endl;
                break;
            }
        }
    }
    return 0;
}
