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
int n,q,i,sq,j;
int freq_pos[100500],freq_neg[100500],freq_ans[100500];
int ans[100500],arr[100500],cnt;
struct block
{
    int l,r,pos;
} query[100500];
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
void add_freq(int index)
{
    if(arr[index]>=0)
    {
        freq_pos[arr[index]]++;
        freq_ans[freq_pos[arr[index]]]++;
        if(freq_ans[cnt+1])
            cnt++;
    }
    else
    {
        freq_neg[arr[index]*-1]++;
        freq_ans[freq_neg[arr[index]*-1]]++;
        if(freq_ans[cnt+1])
            cnt++;
    }
}
void remove_freq(int indx)
{
    if(arr[indx]>=0)
    {
        freq_ans[freq_pos[arr[indx]]]--;
        freq_pos[arr[indx]]--;
        if(freq_ans[cnt]==0 && cnt>0)
            cnt--;
    }
    else
    {
        //cout<<arr[indx]<<endl;
        freq_ans[freq_neg[arr[indx]*-1]]--;
        freq_neg[arr[indx]*-1]--;
        if(freq_ans[cnt]==0 && cnt>0)
            cnt--;
    }
}
int main()
{
//freopen("output.txt", "w", stdout);
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        scanf("%d",&q);
        fill(freq_pos,freq_pos+100050,0);
        fill(freq_neg,freq_neg+100050,0);
        fill(freq_ans,freq_ans+100050,0);
        sq=sqrt(n);
        for(i=0; i<n; i++)
            scanf("%d",&arr[i]);
        for(i=0; i<q; i++)
        {
            scanf("%d %d",&query[i].l,&query[i].r);
            query[i].pos=i;
        }
        sort(query,query+q, cmp);
        int st,en;
        cnt=0;
        st=query[0].l-1;
        en=query[0].r-1;
        for(i=st; i<=en; i++)
        {
            add_freq(i);
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
                    add_freq(j);
                st=l;
            }
            else
            {
                for(j=st; j<l; j++)
                {
                    remove_freq(j);
                }
                st=l;
            }
            if(r>en)
            {
                for(j=en+1; j<=r; j++)
                    add_freq(j);
                en=r;
            }
            else
            {

                for(j=en; j>r; j--)
                    remove_freq(j);
                en=r;
            }
            // cout<<" "<<l<<"   "<<r<< "      " <<cnt<<endl;
            ans[pos]=cnt;
        }
        for(i=0; i<q; i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
