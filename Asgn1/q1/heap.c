#include<stdio.h>
#include<stdlib.h>
#include "heap.h"

HEAP * createHeap(){

HEAP * h = (HEAP *)malloc(sizeof(HEAP));
h->size = 0;                   // create and return an empty heap
h->MAX = 100;
return h;

}

int isEmptyHeap(HEAP * h){      // return 1 if heap is empty, otherwise 0

if(h->size == 0) return 1;
return 0;

}

int isFullHeap(HEAP * h){       // return 0 if heap is full otherwise 0

if(h->size == h->MAX) return 1;
return 0;

}

int findMin(HEAP * h){          // return the min element of a min heap
if(!isEmptyHeap(h)) return h->heap[0];
return -1;
}

void swap(int * a , int * b){    // swap two integers
int temp = (*a);
(*a) = (*b);
(*b) = temp;
return;
}

void min_heapify(HEAP * h,int first){   // the min heapify function - O(log n) time

int i = first;
int last = h->size -1;
while(1){
    int l = 2*i+1;
    int r = 2*i+2;

    if(l > last) return;

    int mN = r;

    if(r > last) mN = l;
    else if(h->heap[l] < h->heap[r]) mN = l;

    if(h->heap[i] <= h->heap[mN]) return;

    swap(&(h->heap[i]) , &(h->heap[mN]));
    i = mN;
}

return;
}

void delete_min(HEAP * h){    // to delete the top (minimum) element from a min heap - O(log n) time

h->heap[0] = h->heap[h->size -1];
(h->size)--;

min_heapify(h,0);

return;
}

void insert_min(HEAP * h,int ele){     // to insert an element in a min heap - O(log n) time

(h->size)++;
h->heap[(h->size)-1] = ele;

int i = (h->size)-1;
int parent;

while(1){
    if(i==0) return;

    parent = (i-1)/2;

    if(h->heap[parent] <= h->heap[i]) return;

    swap(&(h->heap[i]) , &(h->heap[parent]));
    i = parent;
}

return;
}

void build_Heap(HEAP * h){   // build heap - O(n) time

int i;
for(i=h->size/2 - 1;i>=0;i--){
    min_heapify(h,i);
}

return;
}

