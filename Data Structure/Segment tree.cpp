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
int arr[100005],segment_tree[262144];
void Construct_Tree(int low,int high,int pos)
{
    if(low==high)
    {
        segment_tree[pos]=arr[low];
        return ;
    }
    int mid=(low+high)/2;
    Construct_Tree(low,mid,pos*2+1);
    Construct_Tree(mid+1,high,pos*2+2);
    segment_tree[pos]=min(segment_tree[2*pos+1],segment_tree[2*pos+2]);
}
int Range_min_query(int st,int en,int low,int high,int pos)
{

    if(st<=low && en>=high)
        return segment_tree[pos];//total overlap

    if(st>high || en<low)
        return INT_MAX;// no overlap

    int mid=(low+high)/2;

    return min(Range_min_query(st,en,low,mid,2*pos+1),Range_min_query(st,en,mid+1,high,2*pos+2));
}
void update(int low,int high,int pos,int idx,ll val)
{
    if(low>high || idx<low || idx>high)
        return;
    if(low==high && low==idx)
    {
        segment_tree[pos]=val;
        return ;
    }
    int a,b,mid;
    mid=(low+high)/2;
    update(low,mid,pos*2+1,idx,val);
    update(mid+1,high,pos*2+2,idx,val);
    a=pos*2+1;
    b=pos*2+2;
    segment_tree[pos]=min(segment_tree[a],segment_tree[b]);
}
int main()
{
//freopen("output.txt", "w", stdout);

    int t,n,q,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for(int i=0; i<n; i++)
            scanf("%d",&arr[i]);
        Construct_Tree(0,n-1,0);
        int st,en;
        printf("Case %d:\n",cs++);
        while(q--)
        {
            scanf("%d %d",&st,&en);
            int ans=Range_min_query(st-1,en-1,0,n-1,0);

            printf("%d\n",ans);
        }
    }
    return 0;
}
