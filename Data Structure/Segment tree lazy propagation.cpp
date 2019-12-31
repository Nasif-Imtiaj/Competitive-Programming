void LazyPropagate(int node,int left,int right )
{
    int mid = ( right + left ) / 2;
    if( left != right )
    {
        Lazy[2*node] += Lazy[node];
        Lazy[2*node+1] += Lazy[node];
    }
    sum[node] += ( ( right - left) +1 ) * Lazy[node];
    Lazy[node] = 0;
}
void ini(int node,int left,int right)
{
    Lazy[node] = 0;
    sum[node] = 0;
    if(left==right)
        return ;
    int mid = ( right + left ) /2;
    ini(2*node,left,mid);
    ini(2*node+1,mid+1,right);

}
void update(int node,int left,int right,int a,int b,int val)
{
    //
    // printf("a::%d b::%d  lef::%d rgt::%d\n",a,b,left,right);
    if(Lazy[node])
        LazyPropagate(node,left,right);
    if( a > right || b < left )
        return ;
    if( a <= left && b>= right )
    {
        sum[node] += ((right-left)+1)*val;
        Lazy[node] += val;
        if(left!=right)
        {
            Lazy[2*node] +=Lazy[node];
            Lazy[2*node+1] +=Lazy[node];
        }
        Lazy[node] = 0;
        return ;
    }
    int mid = ( right + left ) /2;
    update(2*node,left,mid,a,b,val);
    update(2*node+1,mid+1,right,a,b,val);
    sum[node] = sum[2*node] + sum[2*node+1];
}
int query(int node,int left,int right,int a,int b)
{
    if(Lazy[node])
        LazyPropagate(node,left,right);
    if( a > right || b < left )
        return 0;
    if( a <= left && b>= right )
        return sum[node];
    int mid = ( left + right ) / 2;
    int res = query(2*node,left,mid,a,b) + query(2*node+1,mid+1,right,a,b);
    return res;
}
