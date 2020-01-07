#include<bits/stdc++.h>
using namespace std;
int num[10000000],temp[10000000];
void mergesort(int start,int last)
{
    if(start==last)
        return;
    int mid=(start+last)/2;
    mergesort(start,mid);
    mergesort(mid+1,last);
    int i,j,k;
    for(i=start,j=mid+1,k=start; k<=last; k++)
    {
        if(i==mid+1)   ///what happens here?
            temp[k]=num[j++];
        else if(j==last+1) ///what happens here also?
            temp[k]=num[i++];
        else if(num[i]<num[j])///swapping starts here
            temp[k]=num[i++];
        else
            temp[k]=num[j++]; ///swapping understandable
    }
    for(k=start; k<=last; k++)
    {
        num[k]=temp[k];
    }
}
int main()
{
    int i,a;
    cin>>a;
    for(i=0; i<a; i++)
        cin>>num[i];
    ///now send in the position values from where u want to sort
    mergesort(0,a-1);
    for(i=0; i<a; i++)
        cout<<num[i]<<endl;
    return 0;
}
