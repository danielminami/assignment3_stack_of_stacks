/*
Daniel Minami <minamid@sheridancollege.ca>
----------------------------------------------------------------------
 */

// Assignment 3

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SETOFSTACKS_SIZE 3
#define MAX_STACK_SIZE 5

typedef struct stack {
    int size;
    int top;
    int *data; 
} stack_t;

stack_t* createStack() {
    stack_t* stack = (stack_t*) malloc (sizeof(stack_t));
    stack->size = MAX_STACK_SIZE;
    stack->top = -1;
    stack->data = (int*) malloc (sizeof(int));
    return stack;
}

void createSet(stack_t **set) {
    for (int i=0; i<SETOFSTACKS_SIZE ;i++) {
        set[i] = createStack();
    }
}

bool isEmpty(stack_t* stack) {
    return stack->top == -1;
}

bool isFull(stack_t* stack) {
    return stack->top == stack->size -1;
}

void push(stack_t **set, int value) {
    for (int i=0; i<SETOFSTACKS_SIZE; i++) {
        if (!isFull(set[i])) {
            set[i]->data[++set[i]->top] = value;
            return;
        }
    }
    printf("\nSorry SetOfStacks is FULL\n");
}

int pop(stack_t **set) {
    for (int i=SETOFSTACKS_SIZE-1; i>=0; i--) {
         if (!isEmpty(set[i])) {
            int temp = set[i]->data[set[i]->top];
            set[i]->data[set[i]->top--] = 0;
            return temp;
        }
    }
    printf("\nSorry SetOfStacks is EMPTY\n");
}

void printSet(stack_t **set) {
    printf("Printing set:\n");
    for (int i=0; i<SETOFSTACKS_SIZE; i++) {
        printf("Stack: ");
        if (isEmpty(set[i])) {
            printf("empty");
        } else {
            for (int j=0; j<MAX_STACK_SIZE ; j ++) {
                if (set[i]->data[j] != 0) {
                    if (j == 0)
                        printf("%d", set[i]->data[j]);
                    else
                        printf(",%d", set[i]->data[j]);
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    
    stack_t* set[SETOFSTACKS_SIZE] = {NULL};
    createSet(set);

    pop(set);
    printSet(set);
    push(set, 1);
    push(set, 2);
    push(set, 3);
    push(set, 4);
    push(set, 5);
    push(set, 6);
    push(set, 7);
    push(set, 8);
    push(set, 9);
    push(set, 10);
    push(set, 11);
    push(set, 12);
    push(set, 13);
    push(set, 14);
    push(set, 15);
    push(set, 16);
    push(set, 17);
    printSet(set);
    pop(set);
    pop(set);
    pop(set);
    pop(set);
    pop(set);
    pop(set);
    pop(set);
    pop(set);
    printSet(set);
    exit(0);
}

