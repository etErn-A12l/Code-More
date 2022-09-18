#include<iostream>
using namespace std;

const int MAX=10;

class stack
{
    private:

    int arr[MAX];
    int top;

    public: 

    stack();
    void push(int item);
    int pop();
};

stack :: stack()
{
    top=-1;
}

void stack :: push(int item)
{
    if(top==MAX-1)
    {
        cout<<"The Stack is full !";
        return;
    }
    top++;
    arr[top]=item;
}

int stack :: pop ( )
{
    if(top==-1)
    {
        cout<<"The Stack is empty !";
        return NULL;
    }
    int data = arr[top];
    top--;
    return data;
}

int main()
{
    stack s;
    s.push(23);
    s.push(27);
    s.push(24);
    s.push(54);
    s.push(87);
    s.push(756);
    s.push(84);
    s.push(90);
    int i=s.pop();
    cout<<i<<" was popped !"<<endl;
    cout<<s.pop()<<" was popped !"<<endl;
    i=s.pop();
    cout<<i<<" was popped !";

    return 0;
}
