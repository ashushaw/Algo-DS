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

int cntOccurance(struct Node **head , int occurance){

    struct Node* temp = *head;
    int count=0;
    while(temp!=NULL){
        if(temp->data==occurance)
            count++;
    }

return count;

}



int main(){

    struct Node* head = NULL;

     push(&head, 20);
     push(&head, 4);
     push(&head, 15);
     push(&head, 8);
     push(&head, 82);
     push(&head, 8);
     push(&head, 2);
     push(&head, 1);
     push(&head, 8);
    printList(head);
    int k=0;

        cin>>k;
    //cout<<"\t";
    //<<getNthFromLast(head,k);
    cout<<"\nThe count is "<<cntOccurance(&head,k);
}
