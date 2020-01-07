#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,ar[10000],i,j,x;

    cin>>a;

    for(i=0;i<a;i++){
        cin>>ar[i];
    }
    for(i=1;i<a;i++){
        x=ar[i];
        j=i-1;
        while(j>=0 && ar[j]>x){
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=x;
    }
   for(i=0;i<a;i++){
    cout<<ar[i]<<" ";
   }
return 0;
}
