#include<bits/stdc++.h>
using namespace std;
int grid[1000][1000],row,col;
int mincost(int m,int n)
{
    if(n<0 || m<0)
        return 9999999;

    else if(m==0 && n==0)
        return grid[m][n];
    else
        return grid[m][n]+min(mincost(m-1,n),mincost(m,n-1));
}
int main()
{

    int i,j;
    cin>>row>>col;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
            cin>>grid[i][j];
    }
    cout<<mincost(row-1,col-1);












}
