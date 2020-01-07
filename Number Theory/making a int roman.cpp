#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define bug cout<<"bug"<<endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
void make_roman(int n)
{
    string ans;
    int need=0;
    int cnt=0;
    if(n>=1000)
    {
        cnt=n/1000;
        n%=1000;///M=1000
        for(int i=0; i<cnt; i++)
            ans+="M";
    }
    if(n>=900)
    {
        cnt=n/900;
        n%=900;///CM=900
        ans+="CM";
    }
    if(n>=500)
    {
        cnt=n/500;
        n%=500;///D=500
        for(int i=0; i<cnt; i++)
            ans+="D";
    }
    if(n>=400)
    {
        cnt=n/400;
        n%=400;///CD=400
        ans+="CD";
    }
    if(n>=100)
    {
        cnt=n/100;
        n%=100;///C=100
        for(int i=0; i<cnt; i++)
            ans+="C";
    }
    if(n>=90)
    {
        cnt=n/90;
        n%=90;///XC=90
        ans+="XC";
    }
    if(n>=50)
    {
        cnt=n/50;
        n%=50;///L=50
        for(int i=0; i<cnt; i++)
            ans+="L";
    }
    if(n>=40)
    {
        cnt=n/40;
        n%=40;///XL=40
        ans+="XL";
    }
    if(n>=10)
    {
        cnt=n/10;
        n%=10;///X=10
        for(int i=0; i<cnt; i++)
            ans+="X";
    }
    if(n>=9)
    {
        cnt=n/9;
        n%=9;///IX=9
        for(int i=0; i<cnt; i++)
            ans+="IX";
    }
    if(n>=5)
    {
        cnt=n/5;
        n%=5;///V=5
        for(int i=0; i<cnt; i++)
            ans+="V";
    }
    if(n>=4)
    {
        cnt=n/4;
        n%=4;///IV=4
        ans+="IV";
    }
    if(n>=1)
    {
        cnt=n/1;
        n%=1;///I=1
        for(int i=0; i<cnt; i++)
            ans+="I";
    }
    cout<<ans<<endl;
}
void make_int(string s)
{
    map<char,int>mp;
    mp['M']=1000;
    mp['D']=500;
    mp['C']=100;
    mp['L']=50;
    mp['X']=10;
    mp['V']=5;
    mp['I']=1;
    int len=s.length();
    int ans=0;
    for(int i=0; i<len; i++)
    {
        if(i+1<len)
        {
            if(mp[s[i]]<mp[s[i+1]])
            {
                ans+=mp[s[i+1]]-mp[s[i]];
                i++;
            }
            else
                ans+=mp[s[i]];
        }
        else
        {
            ans+=mp[s[i]];
        }
    }

    cout<<ans<<endl;
}
int main()
{
//freopen("output.txt", "w", stdout);
    int n;
    while(cin>>n)
    {
        make_roman(n);
    }

    return 0;
}
