#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define p printf("bug\n");
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
struct suffix
{
    int indx;
    int ranks[2];
};
int cmp(struct suffix a, struct suffix b)
{
    return (a.ranks[0] == b.ranks[0])? (a.ranks[1] < b.ranks[1] ?1: 0):
           (a.ranks[0] < b.ranks[0] ?1: 0);
}
vector<int> build_suffix_array(string s)
{
    int len=s.length();
    suffix suffixes[len+1];
    for(int i=0; i<len; i++)
    {
        suffixes[i].indx=i;
        suffixes[i].ranks[0]=s[i]-'a';
        suffixes[i].ranks[1]=((i+1) < len)? (s[i + 1] - 'a'): -1;
    }
    sort(suffixes, suffixes+len, cmp);
    int index[len+1];///this mapping will help to get the next suffix
    for(int j=4; j<2*len; j=j*2)
    {
        int cur_rank=0;
        int prev_rank=suffixes[0].ranks[0];
        suffixes[0].ranks[0] = cur_rank;
        index[suffixes[0].indx] = 0;

        for(int i=1; i<len; i++)
        {
            if (suffixes[i].ranks[0] == prev_rank && suffixes[i].ranks[1] == suffixes[i-1].ranks[1])
            {
                prev_rank = suffixes[i].ranks[0];
                suffixes[i].ranks[0] = cur_rank;
            }
            else
            {
                prev_rank = suffixes[i].ranks[0];
                suffixes[i].ranks[0] = ++cur_rank;
            }
            index[suffixes[i].indx] = i;
        }
        for(int i=0; i<len; i++)
        {
            int nextindex = suffixes[i].indx + j/2;
            suffixes[i].ranks[1] = (nextindex < len)?suffixes[index[nextindex]].ranks[0]: -1;
        }
        sort(suffixes, suffixes+len, cmp);
    }
    vector<int>suffix_arr;
    for (int i = 0; i < len; i++)
        suffix_arr.push_back(suffixes[i].indx);
    return suffix_arr;
}
vector<int> kasai(string s,vector<int>suffix_array)
{
    int len=suffix_array.size();
    vector<int>lcp(len,0);
    vector<int>ranks(len,0);
    int k=0;
    for(int i=0; i<len; i++)
        ranks[suffix_array[i]]=i;

    for(int i=0; i<len; i++,k>0?k--:0)
    {
        if(ranks[i]==len-1)
        {
            k=0;
            continue;
        }
        int j=suffix_array[ranks[i]+1];
        while(i+k<len && j+k<len && s[i+k]==s[j+k])
            k++;
        lcp[ranks[i]]=k;
    }
    return lcp;
}
int main()
{
//freopen("output.txt", "w", stdout);
    vector<int>suffix_array;
    vector<int>lcp;
    string s;
    cin>>s;
    suffix_array=build_suffix_array(s);
    lcp=kasai(s,suffix_array);

   /* for(int i=0; i<suffix_array.size(); i++)
        cout<<suffix_array[i]<<" ";
    cout<<endl;
    for(int i=0; i<lcp.size(); i++)
        cout<<lcp[i]<<" ";
    cout<<endl;*/
    return 0;
}
