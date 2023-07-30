#include <bits/stdc++.h>
using namespace std;


struct LL{
  int data;
  LL *next;  
};
void sortedInsert(struct LL**head , int X)
{
  LL*temp = *head ;
  LL *t = new LL;
  //if list is empty
  if(*head==NULL)
  {
    *head = new LL;
    (*head)->data = X;
    (*head)->next = NULL;
  }
  
  else
  {
    
    if(X < temp->data) //start node
    {
      t = new LL;
      t->data = X;
      t->next = *head;
      *head = t;
    }
      
    else
    {
      while(temp->next != NULL and !(X < temp->next->data && X >= temp->data)) //as it is sorted so X must lie between the consecutive values or else at end
        temp=temp->next;
      
      if(temp->next == NULL) //X will go to end
      {
        temp->next = new LL;
        temp = temp->next;
        temp->data = X;
        temp->next = NULL;
      }
      else //X is inserted in between some nodes in list
      {
        t = new LL;
        t->data = X;
        t->next = temp->next; //make the new node's next as the next of current node because the 't' node will lie between consecutive nodes
        temp->next = t;
      }
    }
  }
}
void display(struct LL**head)
{
  struct LL*temp=*head;
  while(temp!=NULL)
    {
      if(temp->next!=NULL)
      cout<<temp->data<<" ->";
      else
      cout<<temp->data;
      
      temp=temp->next; //move to next node
    }
    //O(number of nodes)
  cout<<endl;
}
int main()
{
  
  struct LL *head = NULL; //initial list has no elements
  cout<<"\nCurrent List is :-\n";
  display(&head);
  sortedInsert(&head,6);
  cout<<"\nCurrent List is :-\n";
  display(&head);
  sortedInsert(&head,16);
  cout<<"\nCurrent List is :-\n";
  display(&head);
  sortedInsert(&head,15);
  cout<<"\nCurrent List is :-\n";
  display(&head);
  sortedInsert(&head,50);
  cout<<"\nCurrent List is :-\n";
  display(&head);
  sortedInsert(&head,1);
  cout<<"\nCurrent List is :-\n";
  display(&head);
  sortedInsert(&head,23);
  cout<<"\nCurrent List is :-\n";
  display(&head);
  
  
  return 0;
}
