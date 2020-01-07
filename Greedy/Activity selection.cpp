///Welcome to Nasif's Code
#include<bits/stdc++.h>
using namespace std;
#define p printf("bug\n");
#define co(q)  cout<<q<<endl;
vector< pair<int,int> >race;
int activity_selection()
{
    int i,ans=0,cur;
    cur=race[0].first;
    for(i=1; i<race.size(); i++)
    {
        if(race[i].second>=cur)
        {
            ans++;
            cur=race[i].first;
        }
    }
    return ans+1;
}
int main()
{
    int a,st,en;
    cin>>a;
    while(a--)
    {
        cin>>st>>en;
        race.push_back(make_pair(en,st));
    }
    sort(race.begin(),race.end());
    cout<<activity_selection()<<endl;
    return 0;
}
/*
3
10 20
10 25
20 30
*/
