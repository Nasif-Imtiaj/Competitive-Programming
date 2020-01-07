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
struct Node
{
    int count_of_letters=0;
    int end_mark=0;
    Node *next[27];
    Node()
    {
        count_of_letters=0;
        end_mark=0;
        for(int i=0; i<26; i++)
            next[i]=NULL;
    }
};
Node *root=new Node();

void insert_word(string s)
{
    Node* current=root;
    int len=s.length();
    for(int i=0; i<len; i++)
    {
        int letter=s[i]-'a';
        if(current->next[letter]==NULL)
            current->next[letter]=new Node();
        current->next[letter]->count_of_letters++;
        current=current->next[letter];
    }
    current->end_mark++;
}

void search_word(string s)
{
    Node* current=root;
    int len=s.length();
    for(int i=0; i<len; i++)
    {
        int letter=s[i]-'a';
        if(current->next[letter]==NULL )
        {
            cout<<"Word Not Found"<<endl;
            return;
        }
        current=current->next[letter];
    }
    cout<<"Word Found"<<endl;
}
void delete_word(Node *current,string s,int pos)
{
    if(pos>=s.length())
        return;
    int letter=s[pos]-'a';
    current->next[letter]->count_of_letters--;
    delete_word(current->next[letter],s,pos+1);
    current->next[letter]=NULL;
    return;
}

int main()
{
//freopen("output.txt", "w", stdout);

    insert_word("abc");

    search_word("abc");

    delete_word(root,"abc",0);

    search_word("abc");




    return 0;
}
