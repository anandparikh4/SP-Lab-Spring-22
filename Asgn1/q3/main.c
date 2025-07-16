#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "/usr/include/lib/headers/defs.h"
#include "/usr/include/lib/headers/llist.h"
#include "/usr/include/lib/headers/stack.h"
#include "/usr/include/lib/headers/queue.h"
#include "/usr/include/lib/headers/heap.h"
#include "/usr/include/lib/headers/union_find.h"
#include "/usr/include/lib/headers/graph.h"


int main(){

char s[300];    // The length of the path string will not be more than 300, practically speaking

printf("Enter the path to input file : ");
scanf("%s", s);

GRAPH g = readGraph(s);
DFS(g);
BFS(g);
MST(g);

return 0;
}
