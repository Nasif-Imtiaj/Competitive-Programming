#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

struct linkedlist
{
    node *head;
    linkedlist();
    ~linkedlist();
    void display();
    void insert_at_end(int value);
    void insert_at_beginning(int value);
    void insert_at_location(int loc,int value);
};

linkedlist :: linkedlist()
{
    head=NULL;
}

linkedlist :: ~linkedlist()
{
    node *temp;
    while(head!=NULL)
    {
        temp=head->next;
        delete head;
        head=temp;
    }
}

void linkedlist :: insert_at_end(int value)
{
    node *add=new node;
    add->data=value;
    add->next=NULL;
    node *temp=head;

    if(head==NULL)
    {
        head=add;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=add;
    }
}

void linkedlist :: insert_at_beginning(int value)
{
    node *add=new node;
    add->data=value;
    add->next=head;
    head=add;
}

void linkedlist :: insert_at_location(int loc,int value)
{
    if(loc==1)
    {
        insert_at_beginning(value);
        return;
    }

    node *add= new node;
    add->data=value;
    node *temp=head;

    int i;

    for(i=2; i<loc; i++)
    {
        temp=temp->next;
    }

    node *extra=temp->next;
    temp->next=add;
    add->next=extra;
}

void linkedlist :: delete_at_begining()
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    node *temp=head;
    head=head->next;
    int show=temp->data;
    cout<<show<<"this value deleted from the list"<<endl;
    delete temp;
}

void linkedlist :: delete_at_end()
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    node *temp=head;
    if(temp->next==NULL)
    {
        int show=temp->data;
        cout<<show<<"this value deleted from the list"<<endl;
        delete temp;
        head=NULL;
        return;
    }
    node *extra;
    while(temp->next!=NULL)
    {
        extra=temp;
        temp=temp->next;
    }
    extra->next=NULL;
    int show=temp->data;
    cout<<show<<"this value deleted from the list"<<endl;
    delete temp;
}

void linkedlist :: delete_at_location(int loc)
{
    if(loc==1)
    {
        delete_at_begining();
        return;
    }

    node *temp=head;

    int i;

    for(i=2; i<loc; i++)
    {
        temp=temp->next;
    }
    node *extra=temp->next;
    node *any=extra->next;
    temp->next=any;
    delete extra;

}

void linkedlist :: display()
{
    cout<<"The list is:"<<endl;
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    node *temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{

    linkedlist x;

    int a,b,c,i,j;

    cin>>a;
    for(i=0; i<a; i++)
    {
        cin>>b;
        x.insert_at_end(b);
    }
    x.display();

    cin>>a>>b;
    x.insert_at_location(a,b);

    x.display();

    x.delete_at_begining();

    x.display();

    x.delete_at_end();

    x.display();

    x.delete_at_location(2);

    x.display();

    return 0;
}
