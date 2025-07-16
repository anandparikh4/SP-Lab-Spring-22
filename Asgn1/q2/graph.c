#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "/usr/include/lib/headers/defs.h"
#include "/usr/include/lib/headers/llist.h"
#include "/usr/include/lib/headers/stack.h"
#include "/usr/include/lib/headers/queue.h"
#include "/usr/include/lib/headers/heap.h"
#include "/usr/include/lib/headers/union_find.h"
#include "graph.h"

GRAPH readGraph(char * Fname){

GRAPH g;

if(Fname == NULL){
    int temp;
    scanf("%d", &temp);
    g.n = temp;

    scanf("%d", &temp);
    g.m = temp;

    g.edge = (edge *)malloc(g.m*sizeof(edge));
    g.a = (int **)malloc(g.n*sizeof(int*));

    int i,j;
    for(i=0;i<g.n;i++){
        g.a[i] = (int*)malloc(g.n*sizeof(int));
        for(j=0;j<g.n;j++) g.a[i][j] = 0;
    }

    for(i=0;i<g.m;i++){
        int x,y,weight;
        scanf("%d", &x);
        scanf("%d", &y);
        scanf("%d", &weight);

        g.a[x][y] = g.a[y][x] = weight;

        g.edge[i].left = x;
        g.edge[i].right = y;
        g.edge[i].weight = weight;
    }
}

else{

    FILE * fp;
    fp = fopen(Fname , "r");

    int temp;
    fscanf(fp,"%d", &temp);
    g.n = temp;

    fscanf(fp,"%d", &temp);
    g.m = temp;

    g.edge = (edge *)malloc(g.m*sizeof(edge));
    g.a = (int **)malloc(g.n*sizeof(int*));

    int i,j;
    for(i=0;i<g.n;i++){
        g.a[i] = (int*)malloc(g.n*sizeof(int));
        for(j=0;j<g.n;j++) g.a[i][j] = 0;
    }

    for(i=0;i<g.m;i++){
        int x,y,weight;
        fscanf(fp,"%d", &x);
        fscanf(fp,"%d", &y);
        fscanf(fp,"%d", &weight);

        g.a[x][y] = g.a[y][x] = weight;

        g.edge[i].left = x;
        g.edge[i].right = y;
        g.edge[i].weight = weight;
    }


    fclose(fp);
}

return g;
}

void DFS_visit(int k,int ** a,STACK * s,bool * visited,int n){

visited[k] = true;
*s = push(*s , k);

int i;
for(i=0;i<n;i++){
    if(a[k][i] > 0 && !visited[i]) DFS_visit(i,a,s,visited,n);
}

return;
}

void DFS(GRAPH g){

bool * visited = (bool *)malloc(g.n*sizeof(bool));
STACK s = createStack();

int i;
for(i=0;i<g.n;i++) visited[i] = false;

for(i=0;i<g.n;i++){
    if(!visited[i]) DFS_visit(i,g.a,&s,visited,g.n);
}

STACK reverse_s = createStack();
int next;

while(!isEmptyStack(s)){
    s = pop(s,&next);
    reverse_s = push(reverse_s,next);
}

printf("\nThe DFS pre-order traversal is :\n");
while(!isEmptyStack(reverse_s)){
    reverse_s = pop(reverse_s,&next);
    printf("%d ", next);
}
printf("\n");

return;
}

void BFS_visit(int k,int ** a,QUEUE * q,bool * visited,int n){

*q = enqueue(*q , k);
visited[k] = true;

int i;
while(!isEmptyQueue(*q)){
    int curr;
    *q = dequeue(*q,&curr);
    printf("%d ", curr);

    for(i=0;i<n;i++){
        if(!visited[i] && a[curr][i] > 0){
            visited[i] = true;
            *q = enqueue(*q,i);
        }
    }
}

return;
}

void BFS(GRAPH g){

QUEUE q = createQueue();
bool * visited = (bool*)malloc(g.n*sizeof(bool));
int i;

for(i=0;i<g.n;i++) visited[i] = false;

printf("\nThe BFS pre-order traversal is :\n");

for(i=0;i<g.n;i++){
    if(!visited[i]) BFS_visit(i,g.a,&q,visited,g.n);
}
printf("\n");

return;
}

void Merge(struct edge *a,int low,int mid,int high,struct edge *c);

void mergesort(struct edge * a,int low,int high);

void MST(GRAPH g){

UNION_FIND * f = createUF(g.n);

int i,temp;
for(i=0;i<g.n;i++) f = make_set(f,i,&temp);           // we do not need to store temp as the index of f->F and the name of the node both are equal to i itself

mergesort(g.edge,0,g.m-1);

edge * new_edge = (edge *)malloc((g.n-1)*sizeof(edge));

int k=0,cost = 0;

for(i=0;i<g.m;i++){
    tree_node * l = findUF(f,g.edge[i].left);
    tree_node * r = findUF(f,g.edge[i].right);

    if(l == r) continue;

    unionUF(f,g.edge[i].left , g.edge[i].right);
    cost += g.edge[i].weight;

    new_edge[k] = g.edge[i];
    k++;

    if(k==g.n-1) break;
}

if(k<g.n-1){
    printf("\nThe graph is disconnected, NO MST EXISTS!\n");
    return;
}

printf("\nEdges in the MST are : \n\n");
for(i=0;i<g.n-1;i++){
    printf("%d %d %d\n",new_edge[i].left , new_edge[i].right , new_edge[i].weight);
}
printf("\nTotal cost of MST = %d\n",cost);

return;
}

void Merge(struct edge *a,int low,int mid,int high,struct edge *c){      // regular merge function

int i=low,j=mid+1,k=0;

while(i<=mid && j<=high){
    if(a[i].weight <= a[j].weight) c[k++] = a[i++];             // sort the edges by their weights, in non-decreasing order
    else c[k++] = a[j++];
}
while(i<=mid) c[k++] = a[i++];
while(j<=high) c[k++] = a[j++];

return;
}

void mergesort(struct edge * a,int low,int high){         // regular merge sort function adapted to take in a customized structure

if(high-low<=0) return;
int mid = (high+low)/2;

mergesort(a,low,mid);
mergesort(a,mid+1,high);

int n = (high-low+1);

struct edge *c = (struct edge *)malloc(n*sizeof(struct edge));

Merge(a,low,mid,high,c);
int i;
for(i=low;i<=high;i++) a[i] = c[i-low];

free(c);

return;
}







