#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define p printf("bug\n");
#define co(q)  cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
int used[20],number[20];
void permutation(int m,int n)
{
    int i;
    if(m==n+1)
    {
        for(i=1; i<=n; i++)
            cout<<number[i]<<" ";
        cout<<endl;
        return;
    }
    for(i=1; i<=n; i++)
        if(used[i]==0)
        {
            used[i]=1;
            number[m]=i;
            permutation(m+1,n);
            used[i]=0;
        }
}
int main()
{
//freopen("output.txt", "w", stdout);



    int a;
   cin>>a;
   permutation(1,a);










    return 0;
}
