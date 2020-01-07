string find_add(string x,string y)
{
    int len1=x.length()-1;
    int len2=y.length()-1;
    int a=0,b=0,carry=0,c;
    string ans;
    while(len1>=0 || len2>=0)
    {
        if(len1>=0)
        {
            a=x[len1]-48;
            len1--;
        }
        if(len2>=0)
        {
            b=y[len2]-48;
            len2--;
        }
        c=a+b+carry;
        carry=0;
        carry=c/10;
        c%=10;
        ans+=c+48;
        a=0,b=0;
    }
    if(carry!=0)
        ans+=carry+48;
    reverse(ans.begin(),ans.end());
    return ans;
}
string find_multi(string s,int a)
{
    int len=s.length();
    string ans="";
    int flg=0;
    int x,y;
    while(a>0)
    {
        x=a%10;
        a/=10;
        int carry=0;
        string temp;
        for(int i=len-1; i>=0; i--)
        {
            y=s[i]-48;
            int z=carry+(x*y);
            carry=0;
            carry=z/10;
            z%=10;
            temp+=z+48;
        }
        if(carry!=0)
            temp+=carry+48;

        reverse(temp.begin(),temp.end());
        for(int j=0;j<flg;j++)
            temp+='0';
        ans=find_add(ans,temp);
       // cout<<ans<<"  "<<temp<<endl;
        flg++;
    }
    return ans;
}
