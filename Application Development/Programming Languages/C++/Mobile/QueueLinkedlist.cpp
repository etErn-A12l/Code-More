#include<iostream>
using namespace std;

class queue
{
	private:
		struct node
		{
			int data;
			node *link;
		}*front,*rear;
	public:
		queue();
		void addq(int);
		int delq();
		void display();
};

queue::queue()
{
	front=rear=NULL;
	cout<<"\nQueue is initialised\n";
}

void queue::addq(int num)
{
	node *temp;
	temp=new node;
	if(temp==NULL)
	{
		cout<<"\nQueue is full!\n";
		return;
	}
	temp->data=num;
	temp->link=NULL;
	if(front==NULL)
	{
		front=rear=temp;
		return;
	}
	rear->link=temp;
	rear=rear->link;
}

int queue::delq()
{
	node *temp;
	int num;
	if(front==NULL)
	{
		cout<<"\nQueue is empty\n";
		return NULL;
	}
	temp=front;
	num=temp->data;
	front=temp->link;
	delete temp;
	return num;
}

void queue::display()
{
	if(front==NULL)
	{
		cout<<"\nQueue is empty\n";
		return;
	}
	node *temp;
	temp=front;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
}

int main()
{
	queue s;
	s.addq(12);
	s.addq(83);
	s.addq(25);
	s.addq(87);
	s.addq(93);
	s.addq(9);
	s.addq(17);
	s.addq(6);
	s.addq(88);
	s.display();
	int i=s.delq();
	cout<<endl<<i<<" is deleted!\n";
	s.display();
	i=s.delq();
	cout<<endl<<i<<" is deleted!\n";
	s.display();
	i=s.delq();
	cout<<endl<<i<<" is deleted!\n";
	s.display();
	s.addq(46);
	s.display();
	return 0;
}
