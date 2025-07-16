#include<stdio.h>
#include<stdlib.h>
#include "defs.h"
#include "llist.h"

LLIST createList(){                     // just define an empty linked list, i.e. the head pointer and return it
    node * head = NULL;
    return head;
};

int searchList(LLIST head,int ele){    // search for the element ele, if found return 1, else return 0

node * p = head;
while(p!=NULL){
    if(p->data == ele) return 1;
    p = p->next;
}

return 0;

}

LLIST insertAtFront(LLIST head, int ele){       // insert node at the front of a linked list

node * p = (node *)malloc(sizeof(node));
p->data = ele;
p->next = head;
return p;

};

LLIST insertAtEnd(LLIST head,int ele){          // insert node at the end of the linked list

node * t = (node *)malloc(sizeof(node));
t->next = NULL;
t->data = ele;

if(head == NULL) return t;

node *p,*q;
p = q = head;
while(p!=NULL){
    q=p;
    p=p->next;
}
q->next = t;

return head;
}

LLIST deleteFromFront(LLIST head , int * ele){     // delete the first node of a linked list

*ele = -1;

if(head == NULL) return NULL;

node * first = head;
head = head->next;

*ele = first->data;
first->next = NULL;
free(first);

return head;

}

LLIST deleteFromEnd(LLIST head , int * ele){       // delete the last node of a linked list

*ele = -1;

if(head == NULL) return NULL;

if(head->next == NULL){
    *ele = head->data;
    free(head);
    return NULL;
}

node *p,*q,*r;
r = p = q = head;

while(p!=NULL){
    r = q;
    q = p;
    p = p->next;
}

r->next = NULL;
*ele = q->data;
free(q);

return head;

};

LLIST deleteList(LLIST head,int ele){       // delete a specific element from a linked list

node *p,*q;
p = q = head;
while(p!=NULL){
    if(p->data == ele){
        if(p == head){
            head = head->next;
            p->next = NULL;
            free(p);
            return head;
        }
        q->next = p->next;
        p->next = NULL;
        free(p);
        return head;
    }
    q = p;
    p = p->next;
}

return head;
}


void printList(LLIST head){         // print the linked list

node * p = head;
printf("\nThe current list is:\n");
while(p!=NULL){
    printf("%d  ",p->data);
    p = p->next;
}
printf("\n");
return;
}
