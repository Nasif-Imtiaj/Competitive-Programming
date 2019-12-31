#include<bits/stdc++.h>
using namespace std;
int arr[100000];               // original array
int block[1000];          // decomposed array
int blk_sz;                      // block size
int input[100000];
// Time Complexity : O(1)
void update(int idx, int val)
{
    int blockNumber = idx / blk_sz;
    block[blockNumber] += val ;
    arr[idx]+= val;
}
// Time Complexity : O(sqrt(n))
int query(int l, int r)
{
    int sum = 0;
    while (l<r and l%blk_sz!=0 and l!=0)
    {
        // traversing first block in range
        sum += arr[l];
        l++;
    }
    while (l+blk_sz <= r)
    {
        // traversing completely overlapped blocks in range
        sum += block[l/blk_sz];
        l += blk_sz;
    }
    while (l<=r)
    {
        // traversing last block in range
        sum += arr[l];
        l++;
    }
    return sum;
}

// Fills values in input[]
void preprocess(int input[], int n)
{
    // initiating block pointer
    int blk_idx = -1;

    // calculating size of block
    blk_sz = sqrt(n);

    // building the decomposed array
    for (int i=0; i<n; i++)
    {
        arr[i] = input[i];
        if (i%blk_sz == 0)
        {
            // entering next block
            // incementing block pointer
            blk_idx++;
        }
        block[blk_idx] += arr[i];
    }
}

// Driver code
int main()
{
    int a,b,c,d,t,m,n;

    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        fill(input,input+100000,0);
        fill(arr,arr+100000,0);
        fill(block,block+1000,0);
        preprocess(input,n);
        while(m--)
        {
            cin>>a;
            if(a==0)
            {
                cin>>b>>c>>d;
                for(int i=b;i<=c;i++){
                    update(i,d);
                }
            }
            else
            {
                cin>>b>>c;
                cout<<query(b,c)<<endl;
            }
        }
    }

    return 0;
}
