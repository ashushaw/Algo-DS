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

struct Node* getMiddle(struct Node *head)
{
   // Your code here
   struct Node* slowptr=head;
   struct Node* slowptr_prev=head;
   struct Node* fastptr=head;

   while(slowptr && fastptr && fastptr->next){
       slowptr_prev=slowptr;
       slowptr=slowptr->next;
       fastptr=fastptr->next->next;

   }
   return slowptr;
}

void reverseLL(struct Node** head)
{
    struct Node* prev   = NULL;
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

bool compareLists(struct Node* head1, struct Node *head2)
{
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else return 0;
    }

    /* Both are empty reurn 1*/
    if (temp1 == NULL && temp2 == NULL)
        return 1;

    /* Will reach here when one is NULL
      and other is not */
    return 0;
}

bool checkPlaindrome(struct Node* head){

    struct Node* slowptr=head;
    struct Node* slowptr_prev=head;
    struct Node* fastptr=head;
    struct Node *midnode = NULL;
   while(slowptr && fastptr && fastptr->next){
       slowptr_prev=slowptr;
       slowptr=slowptr->next;
       fastptr=fastptr->next->next;
    }

   if (fast_ptr != NULL)
        {
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
    slowptr_prev->next=NULL;
    struct Node* middleNode = slowptr;
    struct Node* current= middleNode;
    reverseLL(&current);

    bool res= compareLists(head,current);

    return res;
}

int main(){

    struct Node* head = NULL;

     push(&head, 1);
     push(&head, 2);
     push(&head,3);
     push(&head, 2);
     push(&head, 1);
     //push(&head, 82);
     //push(&head, 8);
    printList(head);
   // int k=0;

   // cin>>k;
    //cout<<"\t";
    //<<getNthFromLast(head,k);
    cout<<checkPlaindrome(head);
}

