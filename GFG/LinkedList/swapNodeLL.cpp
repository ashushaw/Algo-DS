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

void swapNodes(struct Node **head , int x , int y){

    struct Node* prevX = NULL;
    struct Node* currX = *head;
    struct Node* currY = *head;
    struct Node* prevY = NULL;

    if(x==y)
        return;

    while(currX!=NULL && currX->data!=x){

       prevX = currX;
        currX=currX->next;
    }

     while(currY!=NULL && currY->data!=x){
       prevY = currY;

        currY=currY->next;
    }

    // If either x or y is not present, nothing to do
   if (currX == NULL || currY == NULL)
        return ;

   //Handling Head Node case for X
   if(prevX!=NULL)
        prevX->next=currY;
   else
        *head = currY;

   if(prevY!=NULL)
        prevY->next=currX;
   else
        *head = currX;

   struct Node* temp = currY->next;
   //if(prevX!=NULL && prevY!=NULL){


        currY->next = currX->next;
        currX->next = temp;
   //}

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

    //cout<<"The middle elemnt is \t"<<getMiddle(head);

    swapNodes(&head,20 ,85);
    cout<<"Swapped List is \n";
    printList(head);
}
