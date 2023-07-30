#include<iostream>
using namespace std;

class first
{
    private:
    struct node
    {
        int data;                   //initializing the nodes as a structure
        node *link;
    }*a;   
    public: 
    void frontadd(int);             //declaring the functions to operate the linked list
    void afteradd(int,int);
    void endadd(int);
    void del(int);
    void display();

};


void first::frontadd(int num)
{
    node *notun;
    if(a==NULL)
    {
        notun=new node;
        notun->data=num;
        notun->link=NULL;
    }
    else
    {
        notun=new node;
        notun->data=num;
        notun->link=a;
        a=notun;
    }
}

void first::afteradd(int num,int loc)
{
    node *pehla,*dusra;
    pehla=a;
    for(int i=0;i<loc;i++)
    {
        pehla=pehla->link;
        if(pehla==NULL)
        {
            cout<<"\nThere is less nodes than the location you have entered !!";
            return;
        }
    }
    dusra=new node;
    dusra->data=num;
    dusra->link=pehla->link;
    pehla->link=dusra;
}

void first::endadd(int num)
{
    node *temp,*notun;
    temp=a;
    if(a==NULL)
    {
        notun=new node;
        notun->data=num;
        notun->link=NULL;
    }
    else
    {
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        notun=new node;
        notun->data=num;
        notun->link=NULL;
        temp->link=notun;
    }    
}

void first::del(int num)
{
    node *temp,*extra;
    temp=a;
    while(temp!=NULL)
    {
        if(temp->data==num)
        {
            if(temp==a)
            {
                a=temp->link;
                delete temp;
            }
            else
            {
                extra=a;
                while(extra->link!=temp)
                {
                    extra=extra->link;
                }
                extra->link=temp->link;
                delete temp;
            }
        }
        temp=temp->link;
    }
}

void first::display()
{
    node *temp;
    int i=1;
    temp=a;
    while(temp!=NULL)
    {
        cout<<i<<"th element="<<temp->data;
        cout<<endl;
        i++;
        temp=temp->link;
    }
    cout<<"There are "<<i<<" elements present in the list";
}

int main()                   //main function
{
    int data,loc;
    first fir;

    cout<<"\nTo add number at beginning: ";
    cin>>data;
    fir.frontadd(data);
    cout<<"\nTo add at end: ";
    cin>>data;
    fir.endadd(data);
    cout<<"\nTo delete a node, enter the data: ";
    cin>>data;
    fir.del(data);
    cout<<"\nTo view inserted data, press '1': ";
    cin>>data;
    if(data==1)
    {
        fir.display();
        cout<<endl;
    }
    else
    cout<<"\nYou have entered wrong number !!";
    cout<<"\nTo add in a certain position, enter num: ";
    cin>>data;
    cout<<"\nNow enter the location: ";
    cin>>loc;
    fir.afteradd(data,loc);
    return 0;
}