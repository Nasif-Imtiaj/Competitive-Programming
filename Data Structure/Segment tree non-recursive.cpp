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
const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build()    // build the tree
{
    for (int i = n - 1; i > 0; --i)
        t[i] = t[i*2] + t[i*2+1];
}
void modify(int p, int value)    // set value at position p
{
    for (t[p += n] = value; p > 1; p/=2)
        t[p] = t[p] + t[p*2+1];
}
int query(int l, int r)    // sum on interval [l, r)
{
    int res = 0;
    for (l += n, r += n; l < r; l/=2, r/=2)
    {
        if (l%2==1)
            res += t[l++];
        if (r%2==1)
            res += t[--r];
    }
    return res;
}
int main()
{
//freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", t + n + i);
    build();
    printf("%d\n", query(4, 5));
    return 0;
}
