#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e8+7;
const int MAX = 1e6;
#define pi acos(-1)
#define bug cout<<"bug"<<endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
int arr[100005];
int find_LIS(int n )
{
    int LIS[n+5];
    LIS[0] = 1;
    for (int i = 1; i < n; i++ )
    {
        LIS[i] = 1;
        for (int j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && LIS[i] < LIS[j] + 1)
                LIS[i] = LIS[j] + 1;
    }

    // Return maximum value in lis[]
    return *max_element(LIS, LIS+n);
}
int main()
{
//freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    find_LIS(n);
    return 0;
}
