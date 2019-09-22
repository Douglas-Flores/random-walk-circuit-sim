#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "graph.h"
#include "rdmwalk.h"
#define vertex int

main(){
    int num_nodes = 7;

    Graph circ = GRAPHinit(num_nodes);

    //Criando os vértices
    float cost = 0;
    cost = 0.3/(1+0.5);
    createVertex(circ, 0, cost);
    cost = 0.1/(1.0+1.0);
    createVertex(circ, 1, cost);
    cost = 0.05/(1+(1.0/4)+1);
    createVertex(circ, 2, cost);
    cost = 0.05/(1+(1.0/4));
    createVertex(circ, 3, cost);
    createVertex(circ, 4, -1.0);
    createVertex(circ, 5, -1.0);
    createVertex(circ, 6, -1.0);

    //Criando os arcos
    float p = 1/(1+0.5);
    GRAPHinsertArc(circ, 0, circ->v_list[2], p);
    p = 0.5/(1+0.5);
    GRAPHinsertArc(circ, 0, circ->v_list[4], p);

    p = 1.0/(1.0+1.0);
    GRAPHinsertArc(circ, 1, circ->v_list[2], 0.5);
    p = 1.0/(1.0+1.0);
    GRAPHinsertArc(circ, 1, circ->v_list[5], p);

    p = 1.0/(1+(1.0/4)+1);
    GRAPHinsertArc(circ, 2, circ->v_list[0], p);
    p = 1.0/(1+(1.0/4)+1);
    GRAPHinsertArc(circ, 2, circ->v_list[1], p);
    p = (1.0/4)/(1+(1.0/4)+1);
    GRAPHinsertArc(circ, 2, circ->v_list[3], p);

    p = (1.0/4)/(1+(1.0/4));
    GRAPHinsertArc(circ, 3, circ->v_list[2], p);
    p = 1.0/(1+(1.0/4));
    GRAPHinsertArc(circ, 3, circ->v_list[6], p);

    printAdjList(circ);

    walker* e = malloc(sizeof(e));
    e->balance = 0;
    e->vertex_id = 0;

    sim(e, circ, 200);

    printf("\nRodou ate o final! %.2f\n",e->balance);
}

