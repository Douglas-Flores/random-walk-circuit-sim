/* Biblioteca de manipula��o de grafos */
#ifndef _graph_h
#define _graph_h

typedef struct Vertex *vertex;
struct Vertex {
    int id;
    float cost;
    vertex next;
};

/* A lista de adjac�ncia de um v�rtice v � composta por n�s do tipo node. Cada n� da lista corresponde a um arco e cont�m um vizinho w de v e o endere�o do n� seguinte da lista. Um link � um ponteiro para um node. */
typedef struct node *link;
struct node {
   vertex w;
   float probability;
   link next;
};

/* REPRESENTA��O POR LISTAS DE ADJAC�NCIA */
struct graph {
   int V;       // n�mero de v�rtices
   vertex *v_list;   // lista de v�rtices
   int A;       // n�mero de arcos
   link *adj;   // ponteiro para o vetor de listas de adjac�ncia
};
/* Um Graph � um ponteiro para um graph. */
typedef struct graph *Graph;

/* A fun��o NEWnode() recebe um v�rtice w e o endere�o next de um n� e devolve o endere�o a de um novo n� tal que a->w == w e a->next == next. */
static link NEWnode(vertex w, float probability, link next) {
   link a = malloc( sizeof (struct node));
   a->w = w;
   a->probability = probability;
   a->next = next;
   return a;
}

/* FUN��ES */
void createVertex(Graph G, int id, float cost);
Graph GRAPHinit(int V);
void GRAPHinsertArc(Graph G, int v_id, vertex w, float probability);
void printAdjList(Graph G);

#endif
