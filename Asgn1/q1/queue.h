#ifndef _QUEUE
#define _QUEUE

struct QUEUE{
    struct node * front;
    struct node * rear;
};

typedef struct QUEUE QUEUE;

QUEUE createQueue();                  // create and return a new empty queue
int isEmptyQueue(QUEUE);              // check if queue is empty
QUEUE enqueue(QUEUE , int);           // add element to rear of queue
QUEUE dequeue(QUEUE , int *);         // remove element from front of queue
int peekQueue(QUEUE);                 // return front element of queue

#endif
