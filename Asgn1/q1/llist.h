#ifndef _LLIST
#define _LLIST

typedef node * LLIST;

LLIST createList();                             // just define an empty linked list, i.e. the head pointer and return it
int searchList(LLIST head,int ele);             // search for the element ele, if found return 1, else return 0
LLIST insertAtFront(LLIST head, int ele);       // insert node at the front of a linked list
LLIST insertAtEnd(LLIST head,int ele);          // insert node at the end of the linked list
LLIST deleteFromFront(LLIST head , int * ele);  // delete the first node of a linked list
LLIST deleteFromEnd(LLIST head , int * ele);    // delete the last node of a linked list
LLIST deleteList(LLIST head,int ele);           // delete a specific element from a linked list
void printList(LLIST head);                     // print the linked list

#endif
