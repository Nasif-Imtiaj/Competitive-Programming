#include<bits/stdc++.h>
using namespace std;
int freq[10000000];//taking 10^7 as the highest number
int save[10000000];
int pos=0;
int main()
{
    int i,j,a,num,highest=0;
    cin>>a;
    for(i=0;i<a;i++)
    {
        cin>>num;
        freq[num]++;
        if(num>highest)
            highest=num;
    }
    for(i=1;i<=highest;i++){
         while(freq[i]>0){
            cout<<i<<endl;//printing the numbers
            save[pos]=i;//if want to store the numbers after sorting
            pos++;
            freq[i]--;
         }
    }
return 0;
}
