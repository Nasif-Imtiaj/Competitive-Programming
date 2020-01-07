#include<bits/stdc++.h>
using namespace std;
void LISCN(int arr[],int n)
{
    unordered_map<int,int>ump;
    int dp[n],i;
    fill(dp,dp+n,0);
    int maximum=INT_MIN;
    int index=-1;
    for(i=0; i<n; i++)
    {
        if(ump.find(arr[i] - 1)!=ump.end())
        {
            int lastindex=ump[arr[i] - 1] - 1;
            dp[i]=1+dp[lastindex];
        }
        else
            dp[i]=1;

        ump[arr[i]]=i+1;

        if(maximum<dp[i])
        {
            maximum=dp[i];
            index=i;
        }
    }
    cout<<maximum<<endl;
    for(i=arr[index]-maximum+1; i<arr[index]; i++)
        cout<<i<<" ";
    cout<<i<<endl;
}
int main()
{
    int a,b,c,x[100000];;
    cin>>a;
    for(int i=0; i<a; i++)
        cin>>x[i];
    LISCN(x,a);
    return 0;
}
