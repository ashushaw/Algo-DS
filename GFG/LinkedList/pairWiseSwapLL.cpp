#include<bits/stdc++.h>
using namespace std;

int occ[101];

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

struct Node* pairWiseSwap(struct Node *head ){

    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* next_next = NULL;
    struct Node* newHead = current->next;
    while(1){

            next = current->next;
            next_next = next->next;
            next->next = current;
            if(next_next==NULL){
                current->next = NULL;
                break;
            }
            if( next_next->next == NULL){
                current->next = next_next;
                break;
            }
            current->next = next_next->next;
            current = next_next;
    }
    return newHead;
}



int main(){

    struct Node* head = NULL;

     push(&head, 9);
     push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);
    printList(head);
    int k=0;

    //    cin>>k;
    //cout<<"\t";
    //<<getNthFromLast(head,k);
    cout<<"\n";
    head = pairWiseSwap(head);
    printList(head);
}
