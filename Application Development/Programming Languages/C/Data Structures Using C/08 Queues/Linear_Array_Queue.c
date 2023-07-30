// Write a program to implement a linear queue.

#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Changing this value will change length of array

int queue[MAX];

int front = -1, rear = -1;

void enqueue(void);
int dequeue(void);
int peek(void);
void display(void);

int main()
{
    int option, val;
    system("cls");
    do
    {
        printf("\n\n ***** MENU *****");
        printf("\n 1. enqueue an element");
        printf("\n 2. Delete an element");
        printf("\n 3. Peek");
        printf("\n 4. Display the queue");
        printf("\n 5. EXIT");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);
        system("cls");
        switch (option)
        {
        case 1:
            enqueue();
            break;
        case 2:
            val = dequeue();
            if (val != -1)
                printf("\n The number deleted is: % d", val);
            break;
        case 3:
            val = peek();
            if (val != -1)
                printf("\n The first value in queue is: % d", val);
            break;
        case 4:
            display();
            break;
        }
    } while (option != 5);

    return 0;
}

void enqueue()
{
    if (rear == MAX - 1)
    {
        printf("\n OVERFLOW");
        return;
    }
    int num;
    printf("\n Enter the number to be enqueueed in the queue: ");
    scanf("%d", &num);
    if (front == -1 && rear == -1)
        front = rear = 0;
    else
        rear++;
    queue[rear] = num;
    printf("\n%d is enqueueed !",num);
}

int dequeue()
{
    int val;
    if (front == -1 || front > rear)
    {
        printf("\n UNDERFLOW");
        return -1;
    }
    else
    {
        val = queue[front];
        front++;
        if (front > rear)
            front = rear = -1;
        return val;
    }
}

int peek()
{
    if (front == -1 || front > rear)
    {
        printf("\n QUEUE IS EMPTY");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

void display()
{
    int i;
    printf("\n");
    if (front == -1 || front > rear)
        printf("\n QUEUE IS EMPTY");
    else
    {
        printf("\nThe Queue is Below:\n\n\t");
        for (i = front; i <= rear; i++)
            printf("| %d ", queue[i]);
        printf("|");
    }
}