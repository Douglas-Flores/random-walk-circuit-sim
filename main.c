#import <stdio.h>
#import <stdlib.h>
#include "graph.h"
#define vertex int

main(){
    int num_nodes = 4;

    Graph circ = GRAPHinit(num_nodes);
    GRAPHinsertArc(circ, 0, 1);
    GRAPHinsertArc(circ, 1, 0);
    GRAPHinsertArc(circ, 0, 2);
    GRAPHinsertArc(circ, 0, 3);
    GRAPHinsertArc(circ, 3, 1);
    printAdjList(circ);

    printf("\nRodou ate o final!\n");
}

