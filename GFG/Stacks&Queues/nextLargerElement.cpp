#include<bits/stdc++.h>

using namespace std;

struct Stack

{
int top; unsigned capacity; int* array;

};

struct Stack* createStack(unsigned capacity)

{

struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); stack->capacity = capacity;
stack->top = -1;
stack->array = (int*) malloc(stack->capacity * sizeof(int)); return stack;
}

int isFull(struct Stack* stack)

{ return stack->top == stack->capacity - 1; }

int isEmpty(struct Stack* stack) { return stack->top == -1; }

void push(struct Stack* stack, int item)

{
if (isFull(stack)) return;
stack->array[++stack->top] = item;// printf("%d pushed to stack\n", item);

}

int pop(struct Stack* stack)

{
if (isEmpty(stack)) return INT_MIN;

return stack->array[stack->top--];
}

void nextLargerElement(int A[] , int n){

    int i=0;
    struct Stack* s = createStack(n+1);
    int temp=0;
    //first elemented is added to the stack
    push(s , A[0]);
    int nextGreatest = 0;
    for(int i=1;i<n;i++){
        nextGreatest = A[i];
        if(!isEmpty(s)){
            temp = pop(s);


            while(temp<nextGreatest){
                cout<<"The next greatest of "<<A[i]<<" is "<<nextGreatest;
                if(isEmpty(s))
                    break;
                else
                    temp = pop(s);
            }

            if(temp>nextGreatest)
                push(s , temp);
            }
            push(s,nextGreatest);
    }

    while(!isEmpty(s)){
        temp = pop(s);
        cout<<"The next greatest of "<<A[i]<<" is "<<-1;

    }
}

int main(){

    int n=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    nextLargerElement(arr,n);

return 0;

}
