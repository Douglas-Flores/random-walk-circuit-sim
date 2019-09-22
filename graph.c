
#import <stdlib.h>
#include "graph.h"

void createVertex(Graph G, int id, float cost){
    vertex v = malloc(sizeof(struct Vertex));
    v->id = id;
    v->cost = cost;

    G->v_list[id] = v;
}
/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função GRAPHinit() constrói um grafo com vértices 0 1 .. V-1 e nenhum arco. */
Graph GRAPHinit(int V) {
   Graph G = malloc( sizeof *G);
   G->V = V;
   G->v_list = malloc ( V * sizeof (vertex));
   G->A = 0;
   G->adj = malloc( V * sizeof (link));
   for (int v = 0; v < V; v++)
      G->adj[v] = NULL;
   return G;
}
/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função GRAPHinsertArc() insere um arco v-w no grafo G. A função supõe que v e w são distintos, positivos e menores que G->V. Se o grafo já tem um arco v-w, a função não faz nada. */
void GRAPHinsertArc(Graph G, int v_id, vertex w, float probabiblity) {
   for (link a = G->adj[v_id]; a != NULL; a = a->next)
      if (a->w->id == w->id) return;
   G->adj[v_id] = NEWnode(w, probabiblity, G->adj[v_id]);
   G->A++;
}

void printAdjList(Graph G){
    for(int i=0; i < G->V ;i++){
        printf("\nVertex %d(costs %.2f):", i, G->v_list[i]->cost);
        for (link a = G->adj[i]; a != NULL; a = a->next)
            printf(" %d(%.2f)", a->w->id, a->probability);
    }
}
