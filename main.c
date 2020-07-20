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

bool isStackEmpty(stack_t* stack) {
    return stack->top == -1;
}

bool isStackFull(stack_t* stack) {
    return stack->top == stack->size -1;
}

bool isEmpty(stack_t** set) {
    return set[0]->top == -1;
}

int numberOfUsedStacks(stack_t **set) {
    int counter = 0;
    for (int i=0; i<SETOFSTACKS_SIZE ;i++) {
        if (isStackFull(set[i])) counter ++;
    }
    return counter;
}

bool isFull(stack_t** set) {
    return (numberOfUsedStacks(set) > SETOFSTACKS_SIZE-1);
}

void push(stack_t **set, int value) {
    if (!isFull(set)) {
        int i = numberOfUsedStacks(set);
        if (!isStackFull(set[i])) {
            set[i]->data[++set[i]->top] = value;
            return;
        }
    }
    printf("\nSorry SetOfStacks is FULL\n");
}

int pop(stack_t **set) {
    if (!isEmpty(set)) {
        int index = numberOfUsedStacks(set);
        if (isFull(set)) index--;
        if (isStackEmpty(set[index])) --index; 
        int temp = set[index]->data[set[index]->top];
        set[index]->data[set[index]->top--] = 0;
        return temp; 
    } else {
        printf("\nSorry SetOfStacks is EMPTY\n");
        return 0;
    }
}

void printSet(stack_t **set) {
    for (int i=0; i<SETOFSTACKS_SIZE; i++) {
        printf("Stack:");
        if (isStackEmpty(set[i])) {
            printf(" empty");
        } else {
            for (int j=0; j<MAX_STACK_SIZE ; j ++) {
                if (set[i]->data[j] != 0) {
                    char comma = j == 0 ? ' ' : ',';
                    printf("%c%d", comma, set[i]->data[j]);       
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

void testCase1(stack_t** set);
void testCase2(stack_t** set);

int main() {
    
    stack_t* set[SETOFSTACKS_SIZE] = {NULL};
    createSet(set);
    testCase1(set);
   
    exit(0);
}

void testCase2(stack_t** set) {
    push(set, 1);
    push(set, 2);
    push(set, 3);
    push(set, 4);
    push(set, 5);
    push(set, 6);
    push(set, 7);
    printSet(set);
}

void testCase1(stack_t** set) {

    pop(set);
    printSet(set);
    push(set, 1);
    push(set, 2);
    push(set, 3);
    push(set, 4);
    push(set, 5);
    push(set, 6);
    push(set, 7);
    printSet(set);
    push(set, 8);
    push(set, 9);
    push(set, 10);
    push(set, 11);
    push(set, 12);
    push(set, 13);
    push(set, 14);
    push(set, 15);
    printSet(set);
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
    
    printf("\n\n **** FINAL RESULT TEST CASE 1 **** \n\n");
    printSet(set);
    printf("\n **** ------------------------ **** \n\n");
}