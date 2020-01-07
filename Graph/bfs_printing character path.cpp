map<string,string>path;
map<string,int>visit;
map<string,vector<string>>graph_letters;
int bfs(string start,string finish)
{
    queue<string>QS;
    visit[start]=1;
    QS.push(start);
    while(!QS.empty())
    {
        string parent=QS.front();
        QS.pop();
        if(parent==finish)
            return 1;
        for(int i=0;i<graph_letters[parent].size();i++){
         string child=graph_letters[parent][i];
            if(visit[child]==0){
                visit[child]=1;
                path[child]=parent;
                QS.push(child);
            }
        }
    }
return -1;
}
void printpath(string a, string b)
{
    if(a==b)
    {
        return;
    }
    printpath(route[a],b);
    cout<<route[a]<<" "<<a<<endl;;
}
