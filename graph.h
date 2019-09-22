/* Biblioteca de manipulação de grafos */
#ifndef _graph_h
#define _graph_h

typedef struct Vertex *vertex;
struct Vertex {
    int id;
    float cost;
    vertex next;
};

/* A lista de adjacência de um vértice v é composta por nós do tipo node. Cada nó da lista corresponde a um arco e contém um vizinho w de v e o endereço do nó seguinte da lista. Um link é um ponteiro para um node. */
typedef struct node *link;
struct node {
   vertex w;
   float probability;
   link next;
};

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA */
struct graph {
   int V;       // número de vértices
   vertex *v_list;   // lista de vértices
   int A;       // número de arcos
   link *adj;   // ponteiro para o vetor de listas de adjacência
};
/* Um Graph é um ponteiro para um graph. */
typedef struct graph *Graph;

/* A função NEWnode() recebe um vértice w e o endereço next de um nó e devolve o endereço a de um novo nó tal que a->w == w e a->next == next. */
static link NEWnode(vertex w, float probability, link next) {
   link a = malloc( sizeof (struct node));
   a->w = w;
   a->probability = probability;
   a->next = next;
   return a;
}

/* FUNÇÔES */
void createVertex(Graph G, int id, float cost);
Graph GRAPHinit(int V);
void GRAPHinsertArc(Graph G, int v_id, vertex w, float probability);
void printAdjList(Graph G);

#endif
