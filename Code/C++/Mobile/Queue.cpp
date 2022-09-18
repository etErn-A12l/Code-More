//Last in First out(add in rear,delete from front)
#include <iostream>
using namespace std;

void queue(int[]);
void push(int[],int);
int pop(int[]);
void display(int[]);

int main()
{
	int q[7];
	queue(&q[0]);
	push(&q[6], 20);
	push(&q[6], 21);
	push(&q[6], 22);
	push(&q[6], 23);
	push(&q[6], 24);
	push(&q[6], 25);
	push(&q[6], 26);
	push(&q[6], 27);
	display(&q[0]);
	cout << pop(&q[0]) << " popped" << endl;
	cout << pop(&q[0]) << " popped" << endl;
	display(&q[0]);
	return 0;
}

void queue(int a[])
{
	for(int i=0;i<7;i++)
	{
		a[i]=NULL;
	}
	cout<<"queue initialization done\n";
}

void push(int a[], int num)
{
	if (a[6] != NULL) //if queue is full
		{
			cout << "\nQueue is full!";
		}
	for (int i = 6; i >= 0; i--)
	{
		if (a[i] != NULL) //if there is space
		{
			a[i + 1] = num;
		}
		else //if queue is empty
		{
			a[0] = num;
		}
	}
}

int pop(int a[])
{
	if (a[0] == NULL)
	{
		cout << "\nQueue is empty!";
		return 0;
	}
	else
	{
		int num = a[0];
		int i = 1;
		while (a[i] != NULL&&i<7)
		{
			a[i - 1] = a[i];
			i++;
		}
	}
}

void display(int a[])
{
	for (int i = 0; i < 7; i++)
	{
		if (a[0] == NULL)
		{
			cout << "Queue is Empty!";
			break;
		}
		else if (a[i] == NULL)
		{
			break;
		}
		else
		{
			cout << a[i] << " ";
		}
	}
}
