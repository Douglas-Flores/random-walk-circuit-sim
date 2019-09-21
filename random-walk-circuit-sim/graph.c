
#import <stdlib.h>
#include "graph.h"
#define vertex int

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função GRAPHinit() constrói um grafo com vértices 0 1 .. V-1 e nenhum arco. */
Graph GRAPHinit(int V) {
   Graph G = malloc( sizeof *G);
   G->V = V;
   G->A = 0;
   G->adj = malloc( V * sizeof (link));
   for (vertex v = 0; v < V; ++v)
      G->adj[v] = NULL;
   return G;
}
/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função GRAPHinsertArc() insere um arco v-w no grafo G. A função supõe que v e w são distintos, positivos e menores que G->V. Se o grafo já tem um arco v-w, a função não faz nada. */
void GRAPHinsertArc(Graph G, vertex v, vertex w) {
   for (link a = G->adj[v]; a != NULL; a = a->next)
      if (a->w == w) return;
   G->adj[v] = NEWnode(w, G->adj[v]);
   G->A++;
}

void printAdjList(Graph G){
    for(int i=0; i < G->V ;i++){
        printf("\nVertex %d:", i);
        for (link a = G->adj[i]; a != NULL; a = a->next)
            printf(" %d", a->w);
    }
}
