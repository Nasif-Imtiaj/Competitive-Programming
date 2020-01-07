#include<bits/stdc++.h>
using namespace std;
map<int,int>check;
vector<pair<int,int> >graph[100000];
long long int prims(int src)
{
    long long int ans=0;
    priority_queue<pair<int,int> >pq;
    pq.push(make_pair(-1,src));
    while(!pq.empty())
    {
        int cost=pq.top().first*-1;
        int parent=pq.top().second;
        pq.pop();
        if(check[parent]==0)
        {
            // cout<<parent<<" "<<cost<<endl;
            check[parent]=cost;
            ans+=cost;
            for(int i=0; i<graph[parent].size(); i++)
            {
                int child=graph[parent][i].first;
                int child_cost=graph[parent][i].second;
                pq.push(make_pair(child_cost*-1,child));
            }
        }
    }
    return ans-1;
}
int main()
{
    int nodes,edges,t,a,b,c;
    cin>>nodes>>edges;
    while(edges--)
    {
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    cout<<prims(a)<<endl;
    return 0;
}
