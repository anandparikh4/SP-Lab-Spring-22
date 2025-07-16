#ifndef _UNION_FIND
#define _UNION_FIND

struct tree_node{
int key;                    // to store data of nodes
struct tree_node * parent;
int rank;
};

typedef struct tree_node tree_node;
//typedef struct tree_node * NODE_PTR;

struct UNION_FIND{

tree_node** F;
int total;
int max;

};

typedef struct UNION_FIND UNION_FIND;

UNION_FIND * createUF(int n);                                 // create and return a new empty union_find data stucture
UNION_FIND * make_set(UNION_FIND * f , int x , int * idx);    // make a new set
struct tree_node * findUF(UNION_FIND * f , int i);            // find which root a set belongs to
void unionUF(UNION_FIND * f , int i , int j);                 // union two sets

#endif

