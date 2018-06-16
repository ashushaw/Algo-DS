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

void recursiveReverse(struct Node **head){

    struct Node* first;
    struct Node* rest;

    if(*head==NULL)
        return;
    first=*head;
    rest=first->next;

    if(rest==NULL)
        return;
    recursiveReverse(&rest);

    first->next->next=first;
    first->next=NULL;
    *head=rest;
}

struct Node* reverseGrps(struct Node *head , int k){

    int count =0;
    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    while(current!=NULL && count<k ){

        next = current->next;
        current->next = prev ;
        prev = current;
        current = next;
        count++;
    }

    if(next!=NULL)
        head->next = reverseGrps(next , k);

    return prev;
}

int main(){

    struct Node* head = NULL;

     push(&head, 1);
     push(&head, 2);
     push(&head, 3);
     push(&head, 4);
     push(&head, 5);
     push(&head, 6);
     push(&head, 7);
     push(&head ,8);
    printList(head);
    int k=0;

    cin>>k;
    //cout<<"\t";
    //<<getNthFromLast(head,k);
    head = reverseGrps(head , k);
    cout<<"\nReversed list is";
    printList(head);
}
