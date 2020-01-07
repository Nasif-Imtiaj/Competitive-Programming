int arr[1000000],n;
int LIS_nlogn()
{
    vector<int>lis(n+2,MAX);
    lis[0]=-MAX;
    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
        if (lis[j-1] < arr[i] && arr[i] < lis[j])
            lis[j] = arr[i];
    }
    int ans=0;
    for(int i=0; i<=n; i++)
        if(lis[i]<MAX)
            ans=lis[i];
    return ans;
}
