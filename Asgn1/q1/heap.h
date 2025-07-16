#ifndef _HEAP
#define _HEAP

struct HEAP{

int heap[101];
int size;
int MAX;

};

typedef struct HEAP HEAP;

HEAP * createHeap();                   // create and return a new empty heap
int isEmptyHeap(HEAP *);               // return 1 if heap is empty, otherwise
int isFullHeap(HEAP *);                // return 0 if heap is full otherwise 0
int findMin(HEAP *);                   // return the min element of a min heap
void swap(int * , int *);              // swap two integers
void min_heapify(HEAP *,int);          // the main min_heapify function
void delete_min(HEAP *);               // delete the minimum element
void insert_min(HEAP *,int);           // insert a new element
void build_Heap(HEAP *);               // build a heap out of randomly ordered elements

#endif
