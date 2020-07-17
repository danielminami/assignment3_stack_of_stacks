/*
Daniel Minami <minamid@sheridancollege.ca>
----------------------------------------------------------------------
 */

// Assignment 3

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
    int size;
    int top;
    int min;
    int *data; 
} stack_t;

stack_t myStack;

void createStack() {
    //TODO: read the size from users
    myStack.size = 5;
    myStack.top = -1;
    myStack.min = 0;
    myStack.data = (int*) malloc (myStack.size * sizeof(int));
    
}

bool isFull() {
    return myStack.top == myStack.size -1;
}

void push(int newValue) {
    if (isFull()) {
        printf("Stack is full.\n");
        return;
    }
    myStack.top++;
    myStack.data[myStack.top] = newValue;
    setMin(newValue);
}



void setMin(int newValue) {
    if (myStack.top == 0 || newValue < myStack.min) {
        myStack.min = newValue;
    }
}

void printStack() {
    printf("top=%d\n", myStack.top);
    printf("min=%d\n", myStack.min);
    int i=0;
    for (i=0; i < myStack.top + 1; i++) {
        printf("%d ", myStack.data[i]);
    }
    printf("\n");
}

bool isEmpty() {
    return myStack.top == -1;
}

int pop() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    return myStack.data[myStack.top--];
    
}

int main() {
    createStack();
    push(10);
    push(20);
    push(30);
    push(40);
    printStack();
    printf("Item popped %d",pop());
    pop();
    push(5);
    printStack();
    
    exit(0);
}

