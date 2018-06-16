#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head, int new_data)
{

    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));


    new_node->data  = new_data;


    new_node->next = (*head);
    (*head)    = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}


int getMiddle(Node *head)
{
   // Your code here
   Node* slowptr=head;
   Node* fastptr=head;

   while(slowptr && fastptr && fastptr->next){
       slowptr=slowptr->next;
       fastptr=fastptr->next->next;

   }
   return slowptr->data;
}

int main(){

    struct Node* head = NULL;

     push(&head, 20);
     push(&head, 4);
     push(&head, 15);
     push(&head, 85);
     push(&head, 82);
     push(&head, 8);
     push(&head, 47);
    printList(head);

    cout<<"The middle elemnt is \t"<<getMiddle(head);
}
