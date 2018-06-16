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

struct Node* add2LL(struct Node *first , struct Node* second){


    struct Node* currX = first;
    struct Node* currY = second;
    //struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* res_head = NULL;
    struct Node* prev = NULL;
    //newNode = NULL;
     //struct Node*
    int carry=0;
    int sum=0;
    while(currX!=NULL && currY!=NULL){

            sum=((currX->data+currY->data)+carry)%10;
            carry = sum/10;
             struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
             newNode->data=sum;
            newNode->next=NULL;
        // if this is the first node then set it as head of the resultant list
        if(res_head == NULL){
            res_head = newNode;
            prev  = newNode;
        }
        else {// If this is not the first node then connect it to the rest.
            prev->next = newNode;

        // Set prev for next insertion
        prev  = newNode;
        }

        //newNode->data=sum;
        //newNode = newNode->next;
//cout<<"Hello";
        //if(currX)
            currX=currX->next;
        //if(currY)
        currY=currY->next;
    }

    if(currX!=NULL && currY==NULL){
        while(currX!=NULL){
            sum=((currX->data+currY->data)+carry)%10;
            carry = sum/10;
             struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
             newNode->data=sum;
            newNode->next=NULL;
        // if this is the first node then set it as head of the resultant list
       prev->next = newNode;

        // Set prev for next insertion
        prev  = newNode;;
        currX=currX->next;


        }
    }

    if(currY!=NULL && currX==NULL){
        while(currY!=NULL){
            sum=((currX->data+currY->data)+carry)%10;

            carry = sum/10;
             struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
             newNode->data=sum;
            newNode->next=NULL;
        // if this is the first node then set it as head of the resultant list


            prev->next = newNode;

        // Set prev for next insertion
        prev  = newNode;
        currY=currY->next;
        }
    }

 //   newNode->next = NULL;

    return res_head;
}



int main(){

     struct Node* res = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;

    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    printList(first);

    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is ");
    printList(second);

    // Add the two lists and see result
    res = add2LL(first, second);
    printf("Resultant list is ");
    printList(res);

   return 0;
}

