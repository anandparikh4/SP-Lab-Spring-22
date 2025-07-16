#include<stdio.h>
#include<stdlib.h>
#include "defs.h"
#include "stack.h"
#include "llist.h"

STACK createStack(){                // create an empty stack and return it

STACK head = NULL;
return head;

};

int isEmptyStack(STACK head){            // returns 1 if stack is empty, otherwise returns 0

if(head == NULL) return 1;
return 0;

}

STACK push(STACK head , int k){     // push element on top of stack and return modified stack

head = insertAtFront(head , k);
return head;

};

STACK pop(STACK head , int * k){    // pop element from top of stack

*k = -1;
if(!isEmptyStack(head)) head = deleteFromFront(head , k);
return head;

};

int peek(STACK head){               // return top element of stack

if(!isEmptyStack(head)) return head->data;
return -1;

}
