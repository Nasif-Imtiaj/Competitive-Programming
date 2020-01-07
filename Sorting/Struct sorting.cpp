#include<bits/stdc++.h>
using namespace std;
struct box
{
    int num1,num2;
} arr[10000];
bool compare(box l, box r)
{
    if(l.num1<r.num1)
        return 1;
    if(l.num1>r.num1)
        return 0;

    if(l.num2<r.num2)
        return 1;
    if(l.num2>r.num2)
          return 0;
     ///need to add more conditions similar to above for more items

}
int main()
{
    ///can compare multiple items together
    int i,a;

    cin>>a;

    for(i=0; i<a; i++)
        cin>>arr[i].num1>>arr[i].num2;

    sort(arr,arr+a,compare);

    for(i=0; i<a; i++)
        cout<<arr[i].num1<<" "<<arr[i].num2<<endl;
    return 0;
}
