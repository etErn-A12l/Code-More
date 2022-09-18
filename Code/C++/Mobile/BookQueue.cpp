#include <iostream>
using namespace std;

const int MAX=10;

class queue
{
	private:
		int arr[MAX];
		int front,rear;
	public:
		queue();
		void addq(int);
		int delq();
};

//initialises data members
queue::queue()
{
	front=-1;
	rear=-1;
}

//adds an element to the queue
void queue::addq(int item)
{
	if(rear==MAX-1)
	{
		cout<<"\nQueue is full!!\n";
		return ;
	}
	rear++;
	arr[rear]=item;
	if(front==-1)
	{
		front=0;
	}
}

//removes an element from queue
int queue::delq()
{
	int data;
	if(front==-1)
	{
		cout<<"\nQueue is empty\n";
		return NULL;
	}
	data=arr[front];
	arr[front]=0;
	if(front==rear)
		front=rear=-1;
	else
		front++;
	return data;
}

//main function
int main()
{
	queue rupsha;
	
	rupsha.addq(12);
	rupsha.addq(43);
	rupsha.addq(85);
	rupsha.addq(-3);
	rupsha.addq(83);
	
	int i=rupsha.delq();
	cout<<"\nItem deleted: "<<i;
	cout<<"\nItem deleted: "<<rupsha.delq();
	return 0;
}