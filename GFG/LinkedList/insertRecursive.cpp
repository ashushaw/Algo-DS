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


struct Node* insertionRecursive(struct Node* head , int pos,int data){

    if(head==NULL)
    {
        if(pos==0){
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data=data;
            return newNode;
        }
        else
            return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;

    if(pos==0){

        newNode->next=head;
        head=newNode;
        return head;
    }



    struct Node* head_temp = insertionRecursive(head->next,pos-1,data);
    head->next=head_temp;
  return head;
}

struct Node* deletionRecursive(struct Node* head ,int pos){

    if(head==NULL)
    {

            return head;
    }

   if(pos==0)
        head=head->next;



    head->next = deletionRecursive(head->next,pos-1);
    //head->next=head_temp;
  return head;
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

     head=insertionRecursive(head,0,20);
     //insertionRecursive(head,1,10);
     head=insertionRecursive(head,2,30);

     //DELETING 82
     head=deletionRecursive(head,4);
    printList(head);

//    cout<<"The middle elemnt is \t"<<getMiddle(head);
}
