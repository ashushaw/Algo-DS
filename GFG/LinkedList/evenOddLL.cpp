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

struct Node* evenOdd(struct Node **list1){

    struct Node* evenList = NULL;
    struct Node* evenListEnd = NULL;
    struct Node* oddList = NULL;
    struct Node* oddListEnd =  NULL;

    struct Node* current = *list1;

    while(current!=NULL){

            if(current->data%2==0){
                if(evenList==NULL){
                    evenList = evenListEnd = current;
                }
                else{
                    evenListEnd->next=current;
                    evenListEnd=current;
                }

            }

            else{
                if(oddList==NULL){
                    oddList=oddListEnd=current;

                }
                else{
                    oddListEnd->next=current;
                    oddListEnd=current;
                }
            }
        current=current->next;
    }

    evenListEnd->next=oddList;
    oddListEnd->next = NULL;
    *list1=evenList;
    return *list1;
}





int main(){

    struct Node* head = NULL;

     push(&head, 20);
     push(&head, 4);
     push(&head, 15);
     push(&head, 8);
     push(&head, 82);
     push(&head, 7);
     push(&head, 2);
     push(&head, 1);
     push(&head, 8);
    printList(head);
    //int k=0;

      //  cin>>k;
    //cout<<"\t";
    //<<getNthFromLast(head,k);
    cout<<"\nThe modified list is ";
    evenOdd(&head);
    printList(head);
}




