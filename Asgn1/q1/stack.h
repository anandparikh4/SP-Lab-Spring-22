#ifndef _STACK
#define _STACK

typedef node * STACK;

STACK createStack();            // make and return a new empty stack
int isEmptyStack(STACK);        // check if stack is empty
STACK push(STACK , int);        // push element on top of stack
STACK pop(STACK , int *);       // pop element from top of stack
int peek(STACK);                // return top element of stack

#endif

