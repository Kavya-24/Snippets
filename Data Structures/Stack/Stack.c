#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
        int top;
        unsigned int capacity;
        int *array;
} stack;

typedef struct Queue{
    stack* s1;
    stack* s2;
} queue;

stack *newStack(const unsigned int capacity)
{
    stack *pstack = (stack *)calloc(1, sizeof(stack));
    pstack->top = -1;
    pstack->capacity = capacity;
    pstack->array = (int *)calloc(capacity, sizeof(int));
    return pstack;
}
queue *newQueue(const unsigned int capacity){
    queue *pqueue = (queue*)calloc(1, sizeof(queue));
    pqueue->s1 = newStack(capacity);
    pqueue->s2 = newStack(capacity);
    return pqueue;
}

int isEmpty(stack *pstack){
        return pstack->top == -1;
}

int isFull(stack *pstack){
        return pstack->top == pstack->capacity-1;
}

int push(stack *pstack, int data){
        if(isFull(pstack)){
                return -1;
        }
        pstack->array[++(pstack->top)] = data;
        return 0;
}

int pop(stack *pstack){
        if(isEmpty(pstack)){
                return 0;
        }
        return pstack->array[(pstack->top)--];
}

int peek(stack *pstack){
        if(isEmpty(pstack)){
                return 0;
        }
        return pstack->array[pstack->top];
}

void enqueue(queue *pqueue, int data){
    push((pqueue->s1), data);
}

int dequeue(queue *pqueue){
    if(pqueue->s1 == NULL && pqueue->s2 == NULL){
        printf("Queue is Empty");
        return -1;
    }
    if (pqueue->s2 == NULL){

        while(pqueue->s1){
            push(pqueue->s2, pop(pqueue->s1));
        }
    }

    return pop(pqueue->s2);
}

void display(stack *pstack){
    int capacity = pstack->top;
    for(int i = capacity; i >=0; i--){
        printf("%d\n", pstack->array[i]);
    }
}


int main(){
        int n;
        printf("Enter capacity of stack : ");
        scanf("%d",&n);
        stack *stack = newStack(n);
        queue *queue = newQueue(n);
        push(stack,1);
        push(stack,2);
        push(stack,3);
        push(stack,4);
        push(stack,5);
        //display(stack);
        //printf("\npop\n");
        pop(stack);
        //display(stack);
        //printf("\npush\n");
        push(stack, 6);
        //display(stack);
        enqueue(queue, 1);
        enqueue(queue, 2);
        enqueue(queue, 3);
        enqueue(queue, 4);
        enqueue(queue, 5);
        printf("%d", dequeue(queue));
}
