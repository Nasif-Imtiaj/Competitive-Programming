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
int matrix[300][300];
pair<int,pair<int,int> > kadane(int sz,int arr[])
{
    int max_so_far=arr[0];
    int max_ending_here=0;
    int st=0,en=0,point=0;
    for(int i=0; i<sz; i++)
    {
        max_ending_here=max_ending_here+arr[i];
        if(max_so_far<max_ending_here)
        {
            max_so_far=max_ending_here;
            st=point,en=i;
        }
        if(max_ending_here<0)
        {
            max_ending_here=0;
            point=i+1;
        }
    }
    return make_pair(max_so_far,make_pair(st,en));
}
int kadane_2d(int r,int c)
{
    int max_left,max_right,max_up,max_down,max_sum=0;
    for(int L=0; L<c; L++)
    {
        int temp[r];
        for(int i=0; i<r; i++)
            temp[i]=0;
        for(int R=L; R<c; R++)
        {
            for(int i=0; i<r; i++)
            {
                temp[i]+=matrix[i][R];
            }
            pair<int,pair<int,int> >keep=kadane(r,temp);
            int current_sum=keep.first;
            int up=keep.second.first;
            int down=keep.second.second;
            if(current_sum>max_sum)
            {
                max_left=L;
                max_right=R;
                max_up=up;
                max_down=down;
                max_sum=current_sum;
            }
        }
    }
    return max_sum;
}
void make_neg(int x,int y,int z,int w)
{
    for(int i=x; i<=w; i++)
    {
        for(int j=y; j<=z; j++)
        {
            matrix[i][j]=-1;
        }
    }
}
int main()
{
//freopen("output.txt", "w", stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int s;
        scanf("%d",&s);
        for(int i=0; i<s; i++)
            for(int j=0; j<s; j++)
                matrix[i][j]=1;
        int x;
        scanf("%d",&x);
        while(x--)
        {
            int a,b,c,d;
            scanf("%d %d %d %d",&a,&b,&c,&d);
            make_neg(a,b,c,d);
        }

    }
    return 0;
}
