#include<bits/stdc++.h>
using namespace std;
int arr[1000000];
int grid[101][101];
int kadane(int sz)
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
    // cout<<"Positions"<<endl;
    //cout<<"Starting:"<<st<<" Ending:"<<en<<endl;
    return max_so_far;
}
int max_sub_rectangle(int n)
{
    int i,j,k,mx=0;
    for(i=0; i<n; i++)
    {
        fill(arr,arr+n,0);
        for(j=i; j<n; j++)
        {
            for(k=0; k<n; k++)
            {
                arr[k]+=grid[k][j];
            }
            mx=max(mx,kadane(n));
        }
    }
    return mx;
}
int main()
{
    int n,i,j;
    cin>>n;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            cin>>grid[i][j];
    cout<<max_sub_rectangle(n)<<endl;

    return 0;
}
