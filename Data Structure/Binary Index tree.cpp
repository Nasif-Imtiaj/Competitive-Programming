#include<bits/stdc++.h>
using namespace std;
int tree[100001];
int arr[100000];
int query(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
void update(int idx, int x, int n) //n is the size of the array, x is the number to add
{
    while(idx<=n)
    {
        tree[idx]+=x;
        idx += idx & (-idx);
    }
}
void build(int n)
{
    int i;
    for(i=1; i<=n; i++)
        tree[i]=0;
    for(i=1; i<=n; i++)
    {
        update(i,arr[i],n);
    }
}
int main()
{
    int a,b,c,d,e,i;
    cin>>a;
    for(i=1; i<=a; i++)
        cin>>arr[i];
    build(a);
    cin>>b;
    while(b--)
    {
        cin>>c>>d;
        cout<<query(d)-query(c-1)<<endl;
    }
}

/*
5
1 2 3 4 5
3
2 3
1 5
4 5




*/
