#include <iostream>
#include<algorithm>

using namespace std;

struct Graph{
int V;
int E;
struct Edge* edge;

};
struct Edge{
int src;
int dest;
int weight;

};
struct Subset
{
    int rank;
    int parent;

};

struct Graph *createGraph(int V, int E)
{
 struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->E = E;
  graph->V = V;
  graph->edge = (struct Edge*)malloc(graph->E*sizeof(struct Graph));
  return graph;
}

int mycomp(const void *a , const void *b)
{

    struct Edge* a1   = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight  > b1->weight;
}
int find(struct Subset *subset,int i)
{
        if(subset[i].parent != i)
            subset[i].parent  = find(subset,subset[i].parent);

        return subset[i].parent;
}
void Union(struct Subset *subset, int x,int y){
int xroot = find(subset,x);
int yroot = find(subset,y);

if(subset[xroot].rank < subset[yroot].rank)
subset[xroot].parent = yroot;
 else if(subset[xroot].rank > subset[yroot].rank)
subset[yroot].parent = xroot;

 else
    {
        subset[yroot].parent = xroot;
        subset[xroot].rank++;
    }


}

void KruskalMst(struct Graph* graph)
{
 int V = graph->V;
 struct Edge result[V];
 int e= 0 , i = 0;

qsort(graph->edge, graph->E,sizeof(graph->edge[0]),mycomp);
struct Subset *subset = (struct Subset*)malloc(V*sizeof(struct Subset));

for( int v = 0; v < V; v++)
{
    subset[i].parent = i;
    subset[i].rank =0;
    }
    while(e <  V-1)
    {
        struct Edge p = graph->edge[i++];
        int x = find(subset,p.src);
        int y = find(subset, p.dest);
        if(x!=y)
        {
            result[e++] = p;
            Union(subset,x,y);

        }
    }
}

int main()
{
     int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);


    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    KruskalMst(graph);

    return 0;
}
