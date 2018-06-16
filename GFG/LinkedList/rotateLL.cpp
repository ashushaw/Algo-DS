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

int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node* slowptr=head;
   Node* pthNode=NULL;

   for(int i=1;i<n;i++){
       if(slowptr)
       slowptr=slowptr->next;
   }

    cout<<"Temp is at\t"<<slowptr->data;
   while(slowptr){
        if(pthNode==NULL)
            pthNode=head;

        else
            pthNode=pthNode->next;
       slowptr=slowptr->next;
   }


       if(pthNode)
     return pthNode->data;

     else
     return -1;
}
void rotateLL(struct Node **head,int k){

    struct Node* temp = *head;
    //Node* prev = head;
    for(int i=1;i<k;i++){
            //prev=temp;
        if(temp)
            temp=temp->next;
            }
    //prev->next=NULL;
    //cout<<"Prv data is" <<prev->data;
    //cout<<temp->data;

     struct Node* kthNode = temp;
    // cout<<"\n"<<head2->data;
     //Node* temp2= head2;
     while(temp->next)
        temp=temp->next;
    //cout<<temp2->data;
    temp->next=*head;
    *head=kthNode->next;
    kthNode->next=NULL;
}

int main(){

    struct Node* head = NULL;

     push(&head, 20);
     push(&head, 4);
     push(&head, 15);
     push(&head, 85);
     push(&head, 82);
     push(&head, 8);
    printList(head);
    int k=0;

    cin>>k;
    cout<<"\t";
    cout<<"The nthnode is"<<getNthFromLast(head,k);
    //cout<<"\nRotated is";
    //printList(head);
}
