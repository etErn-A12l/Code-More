#include <iostream>
using namespace std;

class queue
{
private:
    struct node
    {
        int item;
        node *link;
    } * rear, *front;

public:
    queue();
    void addq(int item);
    int delq();
    void display();
    // ~queue();
};

queue ::queue()
{
    front = rear = NULL;
}

void queue ::addq(int item)
{
    node *temp;
    temp = new node;
    if (temp == NULL)
    {
        cout << "Queue is full !";
    }
    temp->item = item;
    temp->link = NULL;
    if (front == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->link = temp;
    rear = rear->link;
}

int queue::delq()
{
    if (front == NULL)
    {
        cout << "Queue is empty !";
        return NULL;
    }
    node *temp;
    int item;
    item = front->item;
    temp = front;
    front = front->link;
    delete temp;
    return item;
}

void queue ::display()
{
    if (front == NULL)
        cout << endl
             << "Queue is Empty !";
    return;
    while (front != NULL)
    {
        cout << front->item << " ";
        front = front->link;
    }
}

// queue ::~queue()
// {
//     if (front == NULL)
//         return;
//     node *temp;
//     while (front != NULL)
//     {
//         temp = front;
//         front = front->link;
//         delete temp;
//     }
// }

int main()
{
    queue s;

    s.addq(12);
    s.addq(76);
    s.addq(77);
    s.addq(546);

    s.display();

    return 0;
}
