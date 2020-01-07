///Welcome to Nasif's Code
#include<bits/stdc++.h>
using namespace std;
#define p printf("bug\n");
#define co(q)  cout<<q<<endl;
struct box
{
    int price,weight;
    double ppw;
    string item;
} store[100];
bool comp(box l,box r)
{
    if(l.ppw>r.ppw)
        return true;
    else
        return false;
}
double fractional_knapsack(int a,int bag)
{
    double ans=0;
    int i;
    for( i=0; i<a; i++)
    {
        if(store[i].weight<=bag)
        {
            bag-=store[i].weight;
            ans+=store[i].ppw*store[i].weight;
        }
        else
        {
            ans+=store[i].ppw*bag;
            break;
        }
    }
    return ans;
}
int main()
{
//freopen("output.txt", "w", stdout);
    int a,b,c,d,i,bag;
        cin>>a>>bag;
    getchar();
    for(i=0; i<a; i++)
    {
        cin>>store[i].item>>store[i].price>>store[i].weight;
        store[i].ppw=(double)store[i].price/(double)store[i].weight;
    }
    sort(store,store+a,comp);
    cout<<fractional_knapsack(a,bag)<<endl;
    return 0;
}
/*
3 50
rice 60 10
moyda 80 40
ata 120 30
*/
