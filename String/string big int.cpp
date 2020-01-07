string add(string x,string y)
{
    int len1,len2;
    len1=x.length()-1;
    len2=y.length()-1;
    string ans;
    int a,b,carry=0;
    while(len1>=0|| len2>=0)
    {
        if(len1>=0)
            a=x[len1]-48;
        else
            a=0;
        if(len2>=0)
            b=y[len2]-48;
        else
            b=0;
        int check=a+b+carry;
        carry=0;
        if(check>9)
            carry=1,check%=10;
        ans+=(check+48);
        len1--;
        len2--;
    }
    if(carry!=0)
        ans+=carry+48;
    reverse(ans.begin(),ans.end());
    return ans;
}
string substract(string x,string y)
{
    int len1=x.length()-1;
    int len2=y.length()-1;
    if(len1<len2)
    {
        swap(x,y);
        swap(len1,len2);
    }
    string ans;
    // cout<<x<<" "<<y<<endl;
    int a,b,carry=0;
    while(len1>=0 || len2>=0)
    {
        if(len1>=0)
            a=x[len1]-48;
        else
            a=0;
        if(len2>=0)
            b=y[len2]-48;
        else
            b=0;
        if(a>0 && carry!=0)
            a--,carry=0;
        else if(a==0)
        {
            int c=10-carry;
            c+=a;
            a=c;
            carry=1;
        }
        if(a<b)
        {
            int c=10-carry;
            c+=a;
            a=c;
            carry=1;
        }

        // cout<<a<<" "<<b<<endl;
        int check=a-b;
        ans+=48+check;
        len1--;
        len2--;
    }
    reverse(ans.begin(),ans.end());
    while(ans[0]=='0')
        ans.erase(ans.begin()+0);
    return ans;
}
string multiple(string x,string y)
{
    int len1,len2;
    len1=x.length()-1;
    len2=y.length()-1;
    if(len1<len2)
    {
        swap(x,y);
        swap(len1,len2);
    }
    string ans="";
    int a,b,carry=0,i,j;
    for(j=len2; j>=0; j--)
    {
        string temp;
        carry=0;
        for(i=len1; i>=0; i--)
        {
            a=x[i]-48;
            b=y[j]-48;
            int check=a*b+carry;
            carry=0;
            if(check>9)
                carry=check/10,check%=10;
            //cout<<check<<endl;
            temp+=check+48;
        }
        if(carry!=0)
            temp+=carry+48;
        reverse(temp.begin(),temp.end());
        if(j!=len2)
            temp+='0';
        ans=add(temp,ans);
    }
    return ans;
}
string make_string(int a)
{
    string ans;
    while(a>0)
    {
        ans+=a%10+48;
        a/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
