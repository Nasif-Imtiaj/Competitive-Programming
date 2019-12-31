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
int arr[100005];
vector<int>segment_tree[262144];
void Construct_Tree(int low,int high,int pos)
{
    if(low==high)
    {
        segment_tree[pos].push_back(arr[low]);
        return ;
    }
    int mid=(low+high)/2;
    Construct_Tree(low,mid,pos*2+1);
    Construct_Tree(mid+1,high,pos*2+2);
    merge(segment_tree[pos*2+1].begin(),segment_tree[pos*2+1].end(),
          segment_tree[pos*2+2].begin(),segment_tree[pos*2+2].end(),
          back_inserter(segment_tree[pos]));
}
int Range_element_query(int st,int en,int low,int high,int pos,int val)
{
    if(st<=low && en>=high)
    {
        int l=0,r=(high-low),ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(segment_tree[pos][mid]<=val)
            {
                l=mid+1;
            }
            else{
               ans=max((high-low)-mid+1,ans);
               r=mid-1;
            }
        }
        return ans;
    }
    if(st>high || en<low)
        return 0;// no overlap
    int mid=(low+high)/2;
    return (Range_element_query(st,en,low,mid,2*pos+1,val)+Range_element_query(st,en,mid+1,high,2*pos+2,val));
}
int main()
{
//freopen("output.txt", "w", stdout);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    Construct_Tree(0,n-1,0);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int ans=Range_element_query(a-1,b-1,0,n-1,0,c);
        printf("%d\n",ans);
    }
    return 0;
}

