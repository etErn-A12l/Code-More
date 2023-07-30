#include<bits/stdc++.h>
using namespace std;

class linklist
{
	private:

	struct node
	{
		int data;
		node *next;
	}*p;

	public: 

	linklist();                         //parameterized constructors from here
	void append(int item);
	void addafter(int loc, int item);
	void addatbeg(int item);
	void display();
	int count();
	~linklist();
};

linklist::linklist()
{
	p=NULL;
}

void linklist::append(int item)
{
	if(p==NULL)
	{
		p=new node;
		p->data=item;
		p->next=NULL;
	}
	else
	{
		node *temp, *a;
		temp=p;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		r=new node;
		r->data=item;
		r->next=NULL;
		temp->next=r;
	}	
}

void linklist::addafter(int loc,int item)
{
	node *temp, *u;
	temp=p;

	for(int i=0;i<loc;i++)
	{
		temp=temp->next;
		if(temp==NULL)
		{
			cout<<"There are less nodes than the input location !"<<endl;
			return;
		}
	}
	u=new node;
	u->data=item;
	u->next=temp->next;
	temp->next=u;
}

void linklist::addatbeg(int item)
{
	node *temp;
	temp=new node;
	temp->data=item;
	temp->next=p;
	p=temp;
}

int count()
{
	node *temp=p;
	int c=0;
	while(temp->link!=NULL)
	{
		tmep=temp->link;
		c++;
	}
	return c;
}

void linklist::display()
{
	node *temp=p;
	cout<<endl;
	while(temp->link!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
}

int main()
{
	return 0;
}