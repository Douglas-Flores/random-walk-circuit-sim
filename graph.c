
#import <stdlib.h>
#include "graph.h"
#define vertex int

/* REPRESENTA��O POR LISTAS DE ADJAC�NCIA: A fun��o GRAPHinit() constr�i um grafo com v�rtices 0 1 .. V-1 e nenhum arco. */
Graph GRAPHinit(int V) {
   Graph G = malloc( sizeof *G);
   G->V = V;
   G->A = 0;
   G->adj = malloc( V * sizeof (link));
   for (vertex v = 0; v < V; ++v)
      G->adj[v] = NULL;
   return G;
}
/* REPRESENTA��O POR LISTAS DE ADJAC�NCIA: A fun��o GRAPHinsertArc() insere um arco v-w no grafo G. A fun��o sup�e que v e w s�o distintos, positivos e menores que G->V. Se o grafo j� tem um arco v-w, a fun��o n�o faz nada. */
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
