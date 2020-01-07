#include<bits/stdc++.h>
using namespace std;
int arr[1000000];
void quickSort(int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[(low+high) / 2];
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(low, j);
    if (i < high)
        quickSort(i, high);
}
int main()
{
     int a,i;
    cin>>a;
    for(i=0;i<a;i++)
    {
        cin>>arr[i];
    }
    quickSort(0,a-1);
    for(i=0;i<a;i++)
        cout<<arr[i]<<" ";
}
