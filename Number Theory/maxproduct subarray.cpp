#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define bug cout<<"bug"<<endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
ll arr[1000000];
int MaxProduct(int sz)
{
    ll max_val=arr[0];
    ll min_val=arr[0];
    ll max_product=arr[0];
    for(int i=1;i<sz;i++){
        if(arr[i]<0)
            swap(max_val,min_val);
        max_val=max(max_val*arr[i],arr[i]);
        min_val=min(min_val*arr[i],arr[i]);
        max_product=max(max_product,max_val);
    }
    return max_product;
}
int main()
{
//freopen("output.txt", "w", stdout);
    int a,pos=0;
    while(cin>>a)
    {
        if(a==-999999)
        {
            cout<<MaxProduct(pos)<<endl;
            pos=0;

        }
        else
            arr[pos++]=a;
    }

    return 0;
}
