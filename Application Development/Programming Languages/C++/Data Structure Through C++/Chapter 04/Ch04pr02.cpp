// Program Ch04pr02
// Program to add a new node to the asscending order linked list.

#include <iostream>
using namespace std;

class linklist
{
private:
	// structure containing a data part and link part
	struct node
	{
		int data;
		node *link;
	} * p;

public:
	linklist();
	void add(int num);
	void display();
	int count();
	void del(int num);
	~linklist();
};

// initializes data member
linklist ::linklist()
{
	p = NULL;
}

// adds node to an ascending order linked list
void linklist ::add(int num)
{
	node *r, *temp = p;

	r = new node;
	r->data = num;

	// if list is empty or if new node is to be
	// inserted before the first node
	if (p == NULL || p->data > num)
	{
		p = r;
		p->link = temp;
	}
	else
	{
		// traverse the entire linked list to search the position
		// to insert the new node
		while (temp != NULL)
		{
			if (temp->data <= num && (temp->link->data > num ||
									  temp->link == NULL))
			{
				r->link = temp->link;
				temp->link = r;
				return;
			}

			// go to the next node
			temp = temp->link;
		}
	}
}

// displays the contents of the linked list
void linklist ::display()
{
	node *temp = p;

	cout << endl;
	// traverse the entire linked list
	while (temp != NULL)
	{
		cout << temp->data << "  ";
		temp = temp->link;
	}
}

// counts the number of nodes present in the linked list
int linklist ::count()
{
	node *temp = p;
	int c = 0;

	// traverse the entire linked list
	while (temp != NULL)
	{
		temp = temp->link;
		c++;
	}
	return c;
}

// deallocate memory
linklist ::~linklist()
{
	node *q;

	while (p != NULL)
	{
		q = p->link;
		delete p;
		p = q;
	}
}

int main()
{
	linklist a;

	a.add(5);
	a.add(1);
	a.add(6);
	a.add(4);
	a.add(7);

	cout << "\nElements in the linked list: ";
	a.display();
	cout << "\nNo. of elements in linked list: " << a.count();
	return 0;
}
