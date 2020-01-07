#include<bits/stdc++.h>
using namespace std;
int arr[1000000];
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
    cout<<"Positions"<<endl;
    cout<<"Starting:"<<st<<" Ending:"<<en<<endl;
    return max_so_far;
}
int main()
{
    int n,i;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>arr[i];
    cout<<kadane(n)<<endl;
return 0;
}
