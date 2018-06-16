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


void removeDuplicates(struct Node** head ){

    struct Node * next_next = NULL;

    struct Node* current = *head;
    if(current==NULL)
        return ;

    while(current->next!=NULL){

        if(current->data==current->next->data){
            next_next=current->next->next;
            //deleting the duplicate node
            free(current->next);
            current->next=next_next;

        }
        else
            current=current->next;
    }
}

int main(){

    struct Node* head = NULL;

     push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);
    push(&head, 12);
    push(&head, 12);
    printList(head);

    cout<<"The updated List is\n";
    removeDuplicates(&head);
    printList(head);
}

