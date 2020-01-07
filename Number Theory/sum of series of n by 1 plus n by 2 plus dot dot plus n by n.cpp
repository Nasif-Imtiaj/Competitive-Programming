
///sum of series n/1+n/2+n/3+....n/n
ll root=sqrt(n);
for(int i=1; i<=root; i++)
    sum+=n/i;
sum=(2*sum)-(root*root);
