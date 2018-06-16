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

int intersectionPoint(struct Node *list1 ,struct Node *list2 ){

    struct Node* head1 = list1;
    struct Node* head2 = list2;
    int L1 =0 , L2=0;

    while(head1!=NULL){
            L1++;
        head1=head1->next;
    }

     while(head2!=NULL){
            L2++;
        head2=head2->next;
    }

    int diff=0;
    if(L2>L1){
        head1=list2;
        head2=list1;
        diff=L2-L1;
    }
    else{
        head1=list1;
        head2=list2;
        diff=L1-L2;
    }

    for(int i=0;i<diff;i++)
        head1=head1->next;

    while(head1!=NULL && head2!=NULL){

        if(head1==head2)
            return head1->data;
        head1=head1->next;
        head2->next;
    }



return NULL;
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
