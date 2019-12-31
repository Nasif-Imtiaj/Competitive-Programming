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
int lazy[262144],segment_tree[262144];;
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
    segment_tree[pos]=(segment_tree[2*pos+1]+segment_tree[2*pos+2]);
}
void lazypropagate(int low,int high,int pos)
{
    if(low!=high)
    {
        lazy[pos*2+1]+=lazy[pos];
        lazy[pos*2+2]+=lazy[pos];
    }
    segment_tree[pos]+=((high-low)+1)*lazy[pos];
    lazy[pos]=0;
}
void lazy_range_update(int st,int en,int low,int high,int pos,int val)
{
    if(lazy[pos]>0)
        lazypropagate(low,high,pos);
    if(st>high || en<low)
        return;
    if(st<=low && en>=high)
    {
        segment_tree[pos]=((high-low)+1)*val;
        lazy[pos]+=val;
        if(low!=high)
        {
            lazy[pos*2+1]+=lazy[pos];
            lazy[pos*2+2]+=lazy[pos];
        }
        lazy[pos]=0;
        return ;
    }
    int mid=(low+high)/2;
    lazy_range_update(st,en,low,mid,pos*2+1,val);
    lazy_range_update(st,en,mid+1,high,pos*2+2,val);
    segment_tree[pos]=(segment_tree[2*pos+1]+segment_tree[2*pos+2]);
}
int lazy_range_query(int st,int en,int low,int high,int pos)
{
    if(lazy[pos]>0)
        lazypropagate(low,high,pos);
    if(st>high || en<low)
        return 0;// no overlap
    if(st<=low && en>=high )
        return segment_tree[pos];
    int mid=(low+high)/2;
    int left_side=lazy_range_query(st,en,low,mid,pos*2+1);
    int right_side=lazy_range_query(st,en,mid+1,high,pos*2+2);
    return left_side+right_side;
}
int main()
{
//freopen("output.txt", "w", stdout);

    int n,q;
    scanf("%d %d",&n,&q);
    Construct_Tree(0,n-1,0);
    int a,b,c;
    while(q--)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a==0)
        {
            lazy_range_update(b,c,0,n-1,0,1);
        }
        else
        {
            printf("%d\n",lazy_range_query(b,c,0,n-1,0));
        }
    }

    return 0;
}
