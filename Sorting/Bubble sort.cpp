#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,ar[10000],i,j,x;
    cin>>a;
    for(i=0; i<a; i++)
    {
        cin>>ar[i];
    }
    for(i=0; i<a; i++)
    {
        for(j=0; j<a; j++)
        {
            if(ar[i]<ar[j])
                swap(ar[i],ar[j]);
        }
    }
    for(i=0; i<a; i++)
    {
        cout<<ar[i]<<" ";
    }
    return 0;
}

