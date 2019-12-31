int parent[100065];
int connected[100065];
int find_parent(int a)
{
    if(parent[a]==a)
        return parent[a];
    return find_parent(parent[a]);
}
void merge_childs(int a,int b)
{
    int x=find_parent(a),y=find_parent(b);
    if(x!=y)
    {
        if(x>y)
            swap(x,y);
        parent[x]=y;
        connected[y]+=connected[x];
    }
}
