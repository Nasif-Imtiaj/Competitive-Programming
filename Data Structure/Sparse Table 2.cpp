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
const int MAXN = 100000 + 5;
const int MAX_LOG = 20;
int lg[100005], rmq[20][100005];
void Sparse_Table_Pre_Process(int n)
{
    for(int i=0; i<n; i++)
        rmq[0][i]=arr[i];
    for(int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    for(int i = 1; i <= lg[n]; i++)
        for(int j = 0; j < n - (1 << i) + 1; j++)
            rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
}
int RMQ(int x,int y)
{
    return max(rmq[lg[y - x + 1]][x], rmq[lg[y - x + 1]][y - (1 << lg[y - x + 1]) + 1]);
}
int main()
{
//freopen("output.txt", "w", stdout);






    return 0;
}
