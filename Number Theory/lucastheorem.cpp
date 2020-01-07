int combi(int n,int r,int p)
{
    int save[r+1],i,j;
    fill(save,save+r+1,0);
    save[0]=1;
    for(i=1; i<=n; i++)
    {
        for(j=min(i,r); j>0; j--)
        {
            save[j]=(save[j]+save[j-1])%p;
        }
    }
    return save[r];
}
int lucastheorem(int n,int r,int p)
{
    if(r==0)
        return 1;
    int Ln,Lr;
    Ln=n%p;
    Lr=r%p;
    return (lucastheorem(n/p,r/p,p)*combi(Ln,Lr,p))%p;
}
