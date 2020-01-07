#include<bits/stdc++.h>
using namespace std;
int grid[1000][1000],row,col;
int mincost(int m,int n)
{
    int temp[row][col],i,j;

    temp[0][0]=grid[0][0];

    for(i=1; i<=row; i++)
        temp[i][0]=temp[i-1][0]+grid[i][0];

    for(i=1; i<=col; i++)
        temp[0][i]=temp[0][i-1]+grid[0][i];

    for(i=1; i<=row; i++)
    {
        for(j=1; j<=col; j++)
        {
            temp[i][j]=min(temp[i-1][j],temp[i][j-1])+grid[i][j];
        }
    }

    return temp[m][n];
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
