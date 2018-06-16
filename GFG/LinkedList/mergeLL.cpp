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

struct Node* recursiveMerge(struct Node *list1 ,struct Node *list2 ){

    struct Node* result = NULL;

    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;
    if(list1->data<=list2->data){
        result=list1;
        result->next=recursiveMerge(list1->next,list2);
    }

    else{
        result = list2;
        result->next=recursiveMerge(list1,list2->next);

    }

    return result;
}


struct Node* iterativeMerge(struct Node *list1 ,struct Node *list2){

    struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node)));

    struct Node* temp;

    newNode->next=NULL;
    temp=newNode;
    while(list1!=NULL && list2!=NULL){

            if(list1->data<list1->data){
                temp->next=list1;
                temp=temp->next;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=temp->next;
                list2=list1->next;
            }

    }

    if(list1!=NULL)
        temp->next = list1;

    else
        temp->next = list2;

    temp=newNode->next;
    free(temp);
    return newNode;

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



