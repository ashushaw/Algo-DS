#include<bits/stdc++.h>
using namespace std;

#define MAXSIZE 100

struct Stack{
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity)
{   struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); return stack;
}

int isFull(struct Stack* stack)

{ return stack->top == stack->capacity -1; }

int isEmpty(struct Stack* stack) { return stack->top == -1; }

void push(struct Stack* stack, int item)

{
if (isFull(stack)) return;
stack->array[++stack->top] = item; printf("%d pushed to stack\n", item);

}

int pop(struct Stack* stack)

{
if (isEmpty(stack)) return INT_MIN;

return stack->array[stack->top--];
}

int main()

{

printf("MADE BY ASHUTOSH SHAW IT/2K16/028 \n\n\n")	;

struct Stack* stack = createStack(200);

push(stack, 20); push(stack, 40); push(stack, 60);

printf("%d popped from stack\n", pop(stack));

return 0;

}



