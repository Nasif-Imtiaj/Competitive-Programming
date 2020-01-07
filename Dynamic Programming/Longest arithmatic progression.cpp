#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define bug cout<<"bug"<<endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
int arr[1015];
int dp[1015][1015];
int lenghtOfLongestAP(int n)
{
    int result=2;
    for(int i=0; i<n; i++)
        dp[i][n-1]=2;
    for(int j=n-2; j>=1; j--)
    {
        int i=j-1,k=j+1;
        while(i>=0 && k<=n-1)
        {
            if(arr[i]+arr[k]<2*arr[j])
                k++;
            else if(arr[i]+arr[k]>2*arr[j])
            {
                dp[i][j]=2;
                i--;
            }
            else
            {
                dp[i][j] = dp[j][k] + 1;
                result= max(result, dp[i][j]);
                i--;
                k++;
            }
        }
        while (i >= 0)
        {
            dp[i][j] = 2;
            i--;
        }
    }

return result;
}

int main()
{
//freopen("output.txt", "w", stdout);


    return 0;
}

