int prv[MAX];
void prevLesserElement(int n)
{
    stack<int>s;

    for(int i=1;i<=n;i++)
    {
        while(!s.empty() && arr[i] <= arr[s.top()])
            s.pop();

        if(!s.empty())
            prv[i] = s.top();

        s.push(i);
    }
}
int nxt[MAX];
void nextLesserElement(int n)
{
    stack<int>s;

    for(int i=n;i>=1;i--)
    {
        while(!s.empty() && arr[i] <= arr[s.top()])
            s.pop();

        if(!s.empty())
            nxt[i] = s.top();

        s.push(i);
    }
}

