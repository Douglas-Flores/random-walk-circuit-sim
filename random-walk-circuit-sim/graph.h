/* Biblioteca de manipulação de grafos */
#ifndef _graph_h
#define _graph_h

#define vertex int

/* A lista de adjacência de um vértice v é composta por nós do tipo node. Cada nó da lista corresponde a um arco e contém um vizinho w de v e o endereço do nó seguinte da lista. Um link é um ponteiro para um node. */
typedef struct node *link;
struct node {
   vertex w;
   link next;
};

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA */
struct graph {
   int V;       // número de vértices
   int A;       // número de arcos
   link *adj;   // ponteiro para o vetor de listas de adjacência
};
/* Um Graph é um ponteiro para um graph. */
typedef struct graph *Graph;

/* A função NEWnode() recebe um vértice w e o endereço next de um nó e devolve o endereço a de um novo nó tal que a->w == w e a->next == next. */
static link NEWnode(vertex w, link next) {
   link a = malloc( sizeof (struct node));
   a->w = w;
   a->next = next;
   return a;
}

/* FUNÇÔES */
Graph GRAPHinit(int V);
void GRAPHinsertArc(Graph G, vertex v, vertex w);
void printAdjList(Graph G);

#endif
