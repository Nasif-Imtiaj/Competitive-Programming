string make_roman(int a)
{
    int b;
    string ans;
    if(a/100>0)
    {
        b=a/100;
        while(b--)
            ans+="c";
        a=a%100;
    }
    if(a==0)
    {
        return ans;
    }
    if(a/90>0)
    {
        ans="xc"+ans;
        a=a%90;
    }
    if(a==0)
        return ans;
    if(a/50>0)
    {
        b=a/50;
        while(b--)
            ans+="l";
        a=a%50;
    }
    if(a==0)
        return ans;
    if(a/40>0)
    {
        ans="xl"+ans;
        a=a%40;
    }
    if(a==0)
    {
        return ans;
    }
    if(a/10>0)
    {
        b=a/10;
        while(b--)
            ans+="x";
        a=a%10;
    }
    if(a==0)
    {
        return ans;
    }
    if(a==9)
    {
        ans="ix"+ans;
        return ans;
    }

    if(a/5>0)
    {
        b=a/5;
        while(b--)
            ans+="v";
        a=a%5;
    }
    if(a==0)
    {
        return ans;
    }
    if(a==4)
    {
        ans="iv"+ans;
        return ans;
    }
    if(a%1==0)
    {
        b=a/1;
        while(b--)
            ans+="i";
        a=a%1;
    }
    return ans;
}
