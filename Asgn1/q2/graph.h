struct edge{

int left,right,weight;

};

typedef struct edge edge;

struct GRAPH{

int n,m;
int ** a;
edge * edge;

};

typedef struct GRAPH GRAPH;

void Merge(struct edge *,int ,int ,int ,struct edge *);
void mergesort(edge * , int , int);
GRAPH readGraph(char *);
void DFS_visit(int ,int ** ,STACK * ,bool * ,int);
void DFS(GRAPH);
void BFS_visit(int ,int ** ,QUEUE * ,bool * ,int);
void BFS(GRAPH);
void MST(GRAPH);


