long long phi[10000000];
void computeTotient(int n)
{

    for (int i=1; i<=n; i++)
        phi[i] = i;
    for (int j=2; j<=n; j++)
    {
        if (phi[j] == j)
        {
            phi[j] = j-1;
            for (int i = 2*j; i<=n; i += j)
            {
                phi[i] = (phi[i]/j) * (j-1);
            }
        }
    }
}
