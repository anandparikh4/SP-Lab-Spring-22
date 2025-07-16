#include<stdio.h>
#include<stdlib.h>
#include "union_find.h"

UNION_FIND * createUF(int n){

UNION_FIND * f = (UNION_FIND *)malloc(sizeof(UNION_FIND));
f->F = (struct tree_node ** )malloc(n*sizeof(struct tree_node*));
int i;
for(i=0;i<n;i++) f->F[i] = NULL;

f->total = 0;
f->max = n;
return f;

}

UNION_FIND * make_set(UNION_FIND * f , int x , int * idx){

struct tree_node * new_node = (struct tree_node*)malloc(sizeof(struct tree_node));
new_node->key = x;
new_node->parent = new_node;
new_node->rank = 0;

f->F[f->total] = new_node;
*idx = f->total;
(f->total)++;

return f;
}

struct tree_node * findUF(UNION_FIND * f , int i){

struct tree_node * temp = f->F[i];
while(temp->parent != temp) temp = temp->parent;
return temp;

}

void unionUF(UNION_FIND * f , int i , int j){

struct tree_node * x = findUF(f , i);
struct tree_node * y = findUF(f , j);

if(x == y) return;

if(x->rank > y->rank) y->parent = x;
else if(y->rank > x->rank) x->parent = y;
else{
    y->parent = x;
    (x->rank)++;
}

return;
}



