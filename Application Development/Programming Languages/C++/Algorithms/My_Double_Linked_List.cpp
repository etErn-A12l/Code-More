#include <iostream>
using namespace std;

class double_linklist
{
private:
    // Defining the structure
    struct Double_Linked_List
    {
        // All the data types required inside the structure
        int data;
        Double_Linked_List *next, *previous;
    } * head, *tail; // head refers the first element and tail refers the last element

public:
    // All the operations
    double_linklist();                          // Builds the object
    void forward_display();                     // displays data in foward direction
    void backward_display();                    // displays data in backward direction
    void push(int data);                        // inserts data in front
    void last_insert(int data);                 // inserts data at the end
    void insert_after(int prev_data, int data); // inserts data after a specific data
    int search(int data);                       // searches for a data in the linklist and returns the index
    int pop();                                  // removes data from front
    int last_pop();                             // removes data from last
    void del(int data);                         // removes a specific data
    int length();                               // returns the length of the Linklist
    void sort();                                // sorts the entire linklist in ascending order
    void reverse();                             // reverses the entire linklist
};

double_linklist ::double_linklist()
{
    head = NULL;
    tail = NULL;
}

void double_linklist ::forward_display()
{
    if (head == NULL)
    {
        cout << "Linklist is empty !" << endl;
    }
    else
    {
        Double_Linked_List *temp = head;
        int i = 1;

        while (temp != NULL)
        {
            cout << i << "th element's data: " << temp->data << endl;
            temp = temp->next;
            i++;
        }
        cout << endl
             << "Total " << length() << " elements present in the Linklist !" << endl;
    }
}

void double_linklist ::backward_display()
{
    if (tail == NULL)
    {
        cout << "Linklist is empty !" << endl;
    }
    else
    {
        Double_Linked_List *temp = tail;
        int i = 1;

        while (temp != NULL)
        {
            cout << i << "th element's data: " << temp->data << endl;
            temp = temp->previous;
            i++;
        }
        cout << endl
             << "Total " << length() << " elements present in the Linklist !" << endl;
    }
}

void double_linklist ::push(int data)
{
    Double_Linked_List *temp = new Double_Linked_List;
    temp->data = data;
    temp->previous = NULL;

    if (head == NULL && tail == NULL)
    {
        temp->next = NULL;
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->previous = temp;
        head = temp;
    }
}

void double_linklist ::last_insert(int data)
{
    Double_Linked_List *temp = new Double_Linked_List;
    temp->data = data;
    temp->next = NULL;

    if (head == NULL && tail == NULL)
    {
        temp->previous = NULL;
        head = temp;
        tail = temp;
    }
    else
    {
        temp->previous = tail;
        tail->next = temp;
        tail = temp;
    }
}

void double_linklist ::insert_after(int prev_data, int data)
{
    if (head == NULL && tail == NULL)
    {
        cout << "Linklist is empty !" << endl;
    }
    else
    {
        Double_Linked_List *temp = head;
        // Navigating through the Linklist
        while (temp->data != prev_data && temp->next != NULL)
        {
            temp = temp->next;
        }
        // Checking if the given data found
        if (temp->data == prev_data)
        {
            Double_Linked_List *buffer = new Double_Linked_List;
            buffer->data = data;
            // if element is the only element in the Linklist
            if (temp->previous == NULL && temp->next == NULL && temp == head && temp == tail)
            {
                buffer->next = NULL;
                buffer->previous = head;
                head->next = buffer;
                tail = buffer;
            }
            // if element is the last element
            if (temp->previous != NULL && temp->next == NULL && temp == tail)
            {
                buffer->next = NULL;
                tail->next = buffer;
                buffer->previous = tail;
                tail = buffer;
            }
            // if the element resides in the middle of the linklist or the first element
            if (temp->next != NULL)
            {
                buffer->next = temp->next;
                temp->next->previous = buffer;
                temp->next = buffer;
                buffer->previous = temp;
            }
        }
        else
        {
            cout << "The given element " << prev_data << " was not found in the Linklist !";
        }
    }
}

int double_linklist ::search(int data)
{
    int counter = 1, Index = -1;

    if (head == NULL)
    {
        cout << "Linklist is empty !" << endl;
    }
    else
    {
        Double_Linked_List *temp = head;
        while (temp->data != data && temp->next != NULL)
        {
            temp = temp->next;
            counter++;
        }

        if (temp->data == data)
        {
            cout << "The given Element " << data << " was found at Index: " << counter << endl;
            Index = counter;
        }
        else
        {
            cout << "The given Element " << data << " was not found in the Linklist !" << endl;
        }
    }
    return Index;
}

int double_linklist::pop()
{
    if (head == NULL)
    {
        cout << "Linklist is empty !" << endl;
        return -1;
    }

    int data;
    Double_Linked_List *temp = head;
    data = temp->data;

    // if It is the Only element in the Linklist
    if (head == tail)
    {
        delete head;
        delete tail;
    }

    // if There is Only two elements present in the Linklist
    else if (head->next->next == NULL && head->next == tail)
    {
        head = tail;
        head->previous = NULL;
        delete temp;
    }

    // for normal condition
    else
    {
        head = head->next;
        head->previous = NULL;
        delete temp;
    }

    return data;
}

int double_linklist ::last_pop()
{
    if (head == NULL)
    {
        cout << "Linklist is empty !" << endl;
        return -1;
    }

    int data;
    Double_Linked_List *temp = tail;
    data = temp->data;

    // if there is only one element
    if (head == tail)
    {
        delete head;
        delete tail;
    }

    // if There is only two elements Present in the linklist
    else if (head->next == tail)
    {
        tail = head;
        head->next = NULL;
        delete temp;
    }

    // for normal condition
    else
    {
        tail = temp->previous;
        tail->next = NULL;
        delete temp;
    }

    return data;
}

void double_linklist::del(int data)
{
    if (head == NULL)
    {
        cout << "Linklist is empty !" << endl;
    }
    else
    {
        Double_Linked_List *temp = head;

        while (temp->data != data && temp->next != NULL)
        {
            temp = temp->next;
        }

        if (temp->data == data)
        {
            // IF it is the only element in the Linklist
            if (head == temp && temp == tail)
            {
                delete head;
                delete tail;
            }
            // If it is the first element in the LInklist
            else if (temp == head && temp->previous == NULL)
            {
                temp->next->previous = NULL;
                head = temp->next;
                delete temp;
            }
            // If it is the last element of the Linklist
            else if (temp == tail && temp->next == NULL)
            {
                temp->previous->next = NULL;
                tail = temp->previous;
                delete temp;
            }
            // For normal condition
            else
            {
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
                delete temp;
            }
        }
        else
        {
            cout << "The given element " << data << " was not found in the Linklist !" << endl;
        }
        cout << "The element " << data << " successfully removed from the Linklist !" << endl;
    }
}

int double_linklist::length()
{
    int counter = 1;
    Double_Linked_List *temp = head;
    if (head == NULL)
    {
        cout << "Linklist is empty !" << endl;
        return 0;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
            counter++;
        }
        return counter;
    }
}

void double_linklist ::sort()
{
    if (length() == 0)
    {
        cout << "Linklist is empty ! So can't sort !" << endl;
    }
    else
    {
        Double_Linked_List *current = head;
        Double_Linked_List *temp;

        while (current != NULL)
        {
            temp = current->next;
            while (temp != NULL)
            {
                if (current->data > temp->data)
                {
                    int buffer = current->data;
                    current->data = temp->data;
                    temp->data = buffer;
                }
                temp = temp->next;
            }
            current = current->next;
        }
        cout << "Linklist was sorted successfully !" << endl;
    }
}

void double_linklist::reverse()
{
    if (length() == 0)
    {
        cout << "Linklist is empty !" << endl;
    }
    else
    {
        Double_Linked_List *front = head, *back = tail;

        for (int i = 0; i < length() / 2; i++)
        {
            int temp = front->data;
            front->data = back->data;
            back->data = temp;
            front = front->next;
            back = back->previous;
        }
        cout << endl
             << "Linklist was reversed successfully !" << endl;
    }
}

int main(int argc, char const *argv[])
{
    double_linklist a1;

    a1.push(12);
    a1.push(2);
    a1.push(47);
    a1.push(38);

    // a1.forward_display();
    // cout << endl;
    // a1.backward_display();
    // cout << endl;

    a1.last_insert(66);
    a1.last_insert(78);

    // a1.forward_display();
    // cout << endl;

    a1.insert_after(38, 9);
    a1.insert_after(47, 1);

    // a1.forward_display();
    // cout << endl;

    int index = a1.search(78);

    int pop_var = a1.pop();
    cout << "First Element " << pop_var << " was Popped !" << endl;
    cout << endl;

    pop_var = a1.last_pop();
    cout << "Last Element " << pop_var << " was Popped !" << endl;
    cout << endl;

    a1.del(66);

    // a1.forward_display();
    // cout << endl;

    a1.push(90);

    a1.forward_display();
    cout << endl;

    a1.sort();

    a1.forward_display();
    cout << endl;

    a1.reverse();

    a1.forward_display();
    cout << endl;

    return 0;
}