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
int n,q,i,sq,j;
int ans[50005],freq[100005];
struct block
{
    int l,r,pos;
} query[50005];
bool cmp(block a,block b)
{
    if((a.l/sq)<(b.l/sq))
        return 1;
    if((a.l/sq)>(b.l/sq))
        return 0;
    if(a.r<b.r)
        return 1;
    else
        return 0;
}
int main()
{
//freopen("output.txt", "w", stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int arr[100005];
        fill(freq,freq+100005,0);
        scanf("%d %d",&n,&q);
        sq=sqrt(n);
        for(i=0; i<n; i++)
            scanf("%d",&arr[i]);
        for(i=0; i<q; i++)
        {
            scanf("%d %d",&query[i].l,&query[i].r);
            query[i].pos=i;
        }
        sort(query,query+q, cmp);
        int st,en,cnt=0;
        st=query[0].l-1;
        en=query[0].r-1;
        for(i=st; i<=en; i++)
        {
            freq[arr[i]]++;
            if(freq[arr[i]]==1)
                cnt++;
        }
        ans[query[0].pos]=cnt;
        for(i=1; i<q; i++)
        {
            int l=query[i].l-1;
            int r=query[i].r-1;
            int pos=query[i].pos;
            if(l<st)
            {
                for(j=st-1; j>=l; j--)
                {
                    freq[arr[j]]++;
                    if(freq[arr[j]]==1)
                        cnt++;
                }
                st=l;
            }
            else
            {
                for(j=st; j<l; j++)
                {
                    freq[arr[j]]--;
                    if(freq[arr[j]]==0)
                        cnt--;
                }
                st=l;
            }
            if(r>en)
            {
                for(j=en+1; j<=r; j++)
                {
                    freq[arr[j]]++;
                    if(freq[arr[j]]==1)
                        cnt++;
                }
                en=r;
            }
            else
            {
                for(j=en; j>r; j--)
                {
                    freq[arr[j]]--;
                    if(freq[arr[j]]==0)
                        cnt--;
                }
                en=r;
            }
            // cout<<l<<"   "<<r<< "      " <<cnt<<endl;
            ans[pos]=cnt;
        }
        printf("Case %d:\n",cs++);
        for(i=0; i<q; i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
