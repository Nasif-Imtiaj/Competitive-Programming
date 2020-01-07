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
int main()
{
//freopen("output.txt", "w", stdout);
    int n,cs=1;
    while(cin>>n)
    {
        if(n==0)
            break;
        int arr[n+5];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        sort(arr,arr+n);
        printf("Case %d:\n",cs++);
        int m;
        cin>>m;
        while(m--)
        {
            int req_val;
            cin>>req_val;
            int l=0,r=n-1,sum=0,closest=INT_MAX,closest_sum;
            while(l<r)
            {
                sum=arr[l]+arr[r];
                int test=req_val-sum;
                if(test<0)
                    test*=-1;
                if(test<closest)
                {
                    closest=test;
                    closest_sum=sum;
                }
                if(sum>req_val)
                    r--;
                else
                    l++;
            }
            printf("Closest sum to %d is %d.\n",req_val,closest_sum);
        }
    }

    return 0;
}
