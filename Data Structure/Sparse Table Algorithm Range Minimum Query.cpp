#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define p printf("bug\n");
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
int arr[10000],n;
int sparse[10000][1000];
void Sparse_Table_Pre_Process()
{
    for(int i=0; i<n; i++)
    {
        sparse[i][0]=i;
    }
    for (int j = 1; 1 << j <= n; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            if (arr[sparse[i][j - 1]] <arr[sparse[i + (1 << (j - 1))][j - 1]])
            {
                sparse[i][j] = sparse[i][j - 1];
            }
            else
            {
                sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
            }
        }
    }
}
int RMQ(int low,int high)
{
    int l = high - low + 1;
    int k = log2(l);
    if (arr[sparse[low][k]] <= arr[sparse[low + l - (1<<k)][k]])
    {
        return arr[sparse[low][k]];
    }
    else
    {
        return arr[sparse[high - (1<<k) + 1][k]];
    }
}
int main()
{
//freopen("output.txt", "w", stdout);
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    Sparse_Table_Pre_Process();
    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<RMQ(a-1,b-1)<<endl;
    }
    return 0;
}
