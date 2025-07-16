#include<stdio.h>
#include<stdlib.h>
#include "defs.h"
#include "queue.h"
#include "llist.h"

QUEUE createQueue(){

QUEUE q;
q.front = NULL;
q.rear = NULL;
return q;

};

int isEmptyQueue(QUEUE q){

if(q.front == NULL) return 1;
return 0;

}

QUEUE enqueue(QUEUE q , int ele){

if(isEmptyQueue(q)){
    struct node * t = (struct node *)malloc(sizeof(struct node));
    t->data = ele;
    t->next = NULL;
    q.front = q.rear = t;
    return q;
}

q.rear = insertAtEnd(q.rear , ele);
q.rear = (q.rear)->next;
return q;

}

QUEUE dequeue(QUEUE q , int * k){

*k = -1;

if(isEmptyQueue(q)) return q;

q.front = deleteFromFront(q.front , k);

if(isEmptyQueue(q)) q.rear = NULL;

return q;

}

int peekQueue(QUEUE q){

if(!isEmptyQueue(q)) return (q.front)->data;
return -1;

}
