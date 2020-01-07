#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define p printf("bug\n");
#define co(q)  cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
int lps[1000000];
vector<int>store;
int len1,len2;
void LPS_table(string pat)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < len2)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMP_search(string s,string pat)
{
    len1=s.length();
    len2=pat.length();
    LPS_table(pat);
    int i=0,j=0;
    while (i < len1)
    {
        if (pat[j] == s[i])
        {
            j++;
            i++;
        }
        if (j == len2)
        {
           store.push_back(i-j);
            j = lps[j - 1];
        }
        else if (i < len1 && pat[j] != s[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
int main()
{
//freopen("output.txt", "w", stdout);



    string s,pat;
    cin>>s>>pat;
    KMP_search(s,pat);
    if(store.size()>0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;










    return 0;
}
